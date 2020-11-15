// Demonstrate using a hash function

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#include <cmath>
#include <string.h>

#include "hash_functions.hh"


void usage(void){
    std::cout << "Usage: hashpls -n target_buckets -b pow_base -f file_of_words [-g] [str1, ...]"
              << "\nWhere -g indicates to generate data and compute statistics on a per-algorithm, per-bucket basis" << std::endl;
}

int random_between(int min, int max){
    int diff = random() % (min-max);
    return min+diff;
}

struct hashable_t {
    std::string hashable;
    int query_load;
    int disk_space;
}; 

struct stats_t{
    float average_query_load;
    float average_disk_space;
};

int main(int argc, char* argv[]){
    
    // Hash the given strings and print out
    int target_buckets(0);
    int pow_base(128);
    bool generate_data(false);
    char* filename(NULL);
    int item_ct(0);
    int expected_bucket_size(0);
    std::vector<hashable_t*> to_hash;
    
    // Parse args
    if (argc < 5){
        usage();
        return 1;
    } else {
        // Parse the args out
        // Skip program name
        int i = 1;
        while (i < argc){
            if (strcmp(argv[i], "-n") == 0){
                i++;
                target_buckets = atoi(argv[i]);
            } else if (strcmp(argv[i], "-f") == 0){
                i++;
                filename = argv[i];
            } else if (strcmp(argv[i], "-b") == 0){
                i++;
                pow_base = atoi(argv[i]);
            } else if (strcmp(argv[i], "-g") == 0){
                generate_data = true;
                srand(time(NULL));
            } else {
                hashable_t* obj = new hashable_t;
                obj->hashable = std::string(argv[i]);
                to_hash.push_back(obj);
                item_ct++;
            }
            i++;
        }
    }

    // Error check real quick
    if (buckets == 0){
        std::cerr << "Buckets argument -b missing" << std::endl;
        usage();
        return 1;
    }
    
    // If we were given a file to read, let's get add that to the to_hash vector
    if (filename != NULL){
        std::ifstream myfile;
        myfile.open(filename);
        if (!myfile.is_open()){
            std::cerr << "Failed to open file: " << filename << ", errno: " << errno << std::endl;
            return 1;
        } else {
            // Good to read
            std::string line;
            while (getline(myfile, line)){
                hashable_t* obj = new hashable_t;
                obj->hashable = line;
    
                if (generate_data){
                    // Roughly 10% of objects are enormous and a huge pain
                    // So let's simulate that
                    if (item_ct % 10 == 0){
                        obj->query_load = random_between(1000000, 100000000);
                        obj->disk_space = random_between(500000, 500000000);
                    }
                    obj->query_load = random_between(1000, 10000);
                    obj->disk_space = random_between(500,50000);
                }
                to_hash.push_back(obj);
                item_ct++;
            }
            myfile.close();
        }
    }
    
    // Calculate expected bucket size
    expected_bucket_size = int((float)item_ct / target_buckets);

    // We want to track the distribution and visualize it
    // So let's use a map for it

    // buckets: int->[hashable_t*, hashable_t*]
    // This will actually hold all the hashables so we can analyze them
    typedef std::map<int, std::vector<hashable_t*>> buckets_t;
    typedef std::map<int, stats_t> stats_map_t;
    typedef std::map<int, stats_t>::iterator stats_map_t_iter;
    // META DICTIONARY of HASH FUNCTION TO BUCKETS
    // reason for this is we previously would clear the map, but that would destroy our objects that have been bucketed
    // So we'll hit O(m*n) on space, where m is number of hashing algos, and n is number of objects to be hashed, but doing so makes this easy
    std::map<std::string, buckets_t> hash_func_to_buckets;
    std::map<std::string, stats_map_t> hash_func_to_stats_map; // just for statistics
    std::map<std::string, stats_map_t>::iterator hash_func_to_stats_map_it; // just for statistics
    
    typedef std::pair<int, std::vector<hashable_t*>> mappair;
    // map_iter: iterable of above buckets_t
    std::map<int, std::vector<hashable_t*>>::iterator map_iter;
    std::set<int> unique_buckets_set;
    int highest_entry_count(0);

    std::cout << "Hashing " << item_ct << " items into " << target_buckets << " buckets" << std::endl;
    std::vector<hashable_t*>::iterator vec_iter;
    int hashval(0);
    
    // Get our hash functions so we can iterate and bucket the objects in n number of different ways
    hash_functions_vec_t* hfptr = get_hash_functions();
    hash_functions_vec_t::iterator func_iter;
    func_iter = hfptr->begin();
    while (func_iter != hfptr->end()){
        
        std::cout << "Hashing with " << func_iter->first << "..." << std::endl;
        // Reset our analysis structures and variables
        // Insert into metadictionary for this particular hash function
        buckets_t buckets;
        stats_map_t bucket_to_stats_map;
        hash_func_to_buckets.insert(std::pair<std::string, buckets_t>(func_iter->first, buckets));
        highest_entry_count = 0;

        int (*hash_func)(const char*, int, int)(func_iter->second);
        
        // ** ACTUALLY DO THE HASH AND PUT IN A BUCKET ** 
        for (vec_iter = to_hash.begin(); vec_iter != to_hash.end(); vec_iter++){
            hashval = (*hash_func)((*vec_iter)->hashable.c_str(), target_buckets, pow_base);

            // See if exists
            map_iter = buckets.find(hashval);
            if (map_iter == buckets.end()){
                // Does not exist, insert it
                std::vector<hashable_t*> values;
                values.push_back((*vec_iter));
                buckets.insert(mappair(hashval, values));
            } else {
                // Does exist, so append to the vector there
                map_iter->second.push_back((*vec_iter));
            }

            // Keep an ordered set of the hash buckets as well
            // Allows us to pretty print buckets in ascending order
            unique_buckets_set.insert(hashval);
        }
        
        // Now we can print out and analyze our distribution
        std::set<int>::iterator bucket_iter;
        bucket_iter = unique_buckets_set.begin();
        char pos_ind;

        // in case we're also analyzing generated data, make a map for it
        // This is hash function name to vector of stats_t objects, one for each bucket
        // Then we can get average of bucket stats, and use THAT to compare how each bucket looks to relative average
        std::map<std::string, std::vector<stats_t*>> stats_map;

        while (bucket_iter != unique_buckets_set.end()){
            
            map_iter = buckets.find(*bucket_iter);
            if (map_iter != buckets.end()){
                if (map_iter->second.size() > expected_bucket_size){
                    pos_ind = '+';
                } else { 
                    pos_ind = '-';
                }
                int actual_elements = map_iter->second.size();

                // Print number of elements vs actual
                // e.g. Bucket 1 contains 1010 elements (+ 10, + 1%)
                // Which means this bucket has 10 elements more than the pure average of total items to buckets, which is 1% oversized
                std::cout << "Bucket " << std::setw(floor(log10(target_buckets)+1)) << *bucket_iter << " contains " 
                          << std::setw(floor(log10(item_ct)+1)) << actual_elements << " elements " 
                          << "(" << pos_ind << std::setw(4) << std::abs(actual_elements-expected_bucket_size)
                          << ", " << pos_ind << std::setw(2) 
                          << (int)((std::abs((float)actual_elements-expected_bucket_size)/expected_bucket_size)*100) << "%)\n";

                // In the event we generated data, we can do some additional analysis on the average disk space and query load of these objects
                // For regular word hashing, these values do not exist, so we don't both
                if (generate_data){

                    stats_t this_bucket_stats;
                    
                    float avg_disk(0.0);
                    float avg_query(0.0);
                    // Determine average disk space and query load from vector of hashable_t*
                    for (int i = 0; i < actual_elements; i++){
                        avg_disk += map_iter->second[i]->disk_space;
                        avg_query += map_iter->second[i]->query_load;
                    }
                    this_bucket_stats.average_disk_space = avg_disk / actual_elements;
                    this_bucket_stats.average_query_load = avg_query / actual_elements;

                    // Store both in yet another map because they're cheap and I'm working fast right now
                    // We know buckets are iterated once for function, so can do this cheaply
                    bucket_to_stats_map.insert(std::pair<int, stats_t>(*bucket_iter, this_bucket_stats));

                }
            }

            bucket_iter++;
        }
        hash_func_to_stats_map.insert(std::pair<std::string, stats_map_t>(func_iter->first, bucket_to_stats_map));

        func_iter++;
    }

    // Now we're all done and can print all the stats for all the functions and all the buckets
    func_iter = hfptr->begin();
    while (func_iter != hfptr->end()){

        // Let's make this super simple
        std::string func_name(func_iter->first);
        
        // to get the bucket->stat_t map
        hash_func_to_stats_map_it = hash_func_to_stats_map.find(func_name);

        if (hash_func_to_stats_map_it != hash_func_to_stats_map.end()){
            // hash_func_to_stats_map_it.second is stats_map_t
            stats_map_t b_to_s_map = hash_func_to_stats_map_it->second;
        
            stats_map_t::iterator f_it = b_to_s_map.begin();
            
            // iter all buckets calculated by this hash func and dump avg stats
            std::cout << "Hash function: " << func_name << " stats:\n";
            while (f_it != b_to_s_map.end()){
                std::cout << "\tBucket: " << f_it->first << " avg disk: " << f_it->second.average_disk_space 
                          << ", avg query: " << f_it->second.average_query_load << std::endl;
                f_it++;
            }
            
        }

        func_iter++;
    }

    return 0;
}
