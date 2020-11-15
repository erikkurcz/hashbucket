// Demonstrate using a hash function

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <string>
#include <vector>

#include <cmath>
#include <string.h>

#include "hash_functions.hh"


void usage(void){
    std::cout << "Usage: hashpls -n target_buckets -b pow_base -f file_of_words str1 ..." << std::endl;
}

struct hashable_t {
    std::string hashable;
    int query_load;
    int disk_usage;
}; 

int main(int argc, char* argv[]){
    
    // Hash the given strings and print out
    int target_buckets(0);
    int pow_base(128);
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
            } else {
                hashable_t* obj = new hashable_t;
                obj->hashable = std::string(argv[i]);
                to_hash.push_back(obj);
                item_ct++;
            }
            i++;
        }
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
                to_hash.push_back(obj);
                item_ct++;
            }
            myfile.close();
        }
    }
    
    // Calculate expected bucket size
    expected_bucket_size = int((float)item_ct / target_buckets);

    // Don't want to hash program name, just what's given
    // Also don't want to hash the null values either

    // We want to track the distribution and visualize it
    // So let's use a map for it

    // buckets: int->[hashable_t*, hashable_t*]
    // This will actually hold all the hashables so we can analyze them
    typedef std::map<int, std::vector<hashable_t*>> buckets_t;
    // META DICTIONARY of HASH FUNCTION TO BUCKETS
    // reason for this is we previously would clear the map, but that would destroy our objects that have been bucketed
    // So we'll hit O(m*n) on space, where m is number of hashing algos, and n is number of objects to be hashed, but doing so makes this easy
    std::map<std::string, buckets_t> hash_func_to_buckets;
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

        while (bucket_iter != unique_buckets_set.end()){
            
            map_iter = buckets.find(*bucket_iter);
            if (map_iter != buckets.end()){
                if (map_iter->second.size() > expected_bucket_size){
                    pos_ind = '+';
                } else { 
                    pos_ind = '-';
                }
                int actual_elements = map_iter->second.size();
                std::cout << "Bucket " << std::setw(floor(log10(target_buckets)+1)) << *bucket_iter << " contains " 
                          << std::setw(floor(log10(item_ct)+1)) << actual_elements << " elements " 
                          << "(" << pos_ind << std::setw(4) << std::abs(actual_elements-expected_bucket_size)
                          << ", " << pos_ind << std::setw(2) 
                          << (int)((std::abs((float)actual_elements-expected_bucket_size)/expected_bucket_size)*100) << "%)\n";
            }

            bucket_iter++;
        }

        func_iter++;
    }



    return 0;
}
