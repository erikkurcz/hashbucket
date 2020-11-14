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

#include "hashfunction.hh"

void usage(void){
    std::cout << "Usage: hashpls -n buckets -b pow_base -f file_of_words str1 ..." << std::endl; }

int main(int argc, char* argv[]){
    
    // Hash the given strings and print out
    int buckets(0);
    int pow_base(128);
    char* filename(NULL);
    int item_ct(0);
    int expected_bucket_size(0);
    std::vector<std::string> to_hash;

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
                buckets = atoi(argv[i]);
            } else if (strcmp(argv[i], "-f") == 0){
                i++;
                filename = argv[i];
            } else if (strcmp(argv[i], "-b") == 0){
                i++;
                pow_base = atoi(argv[i]);
            } else {
                to_hash.push_back(std::string(argv[i]));
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
                to_hash.push_back(line);
                item_ct++;
            }
            myfile.close();
        }
    }
    
    // Calculate expected bucket size
    expected_bucket_size = int((float)item_ct / buckets);

    // Don't want to hash program name, just what's given
    // Also don't want to hash the null values either

    // We want to track the distribution and visualize it
    // So let's use a map for it
    std::map<int, int> map;
    std::map<int, int>::iterator map_iter;
    typedef std::pair<int, int> mappair;
    std::set<int> unique_buckets;

    std::cout << "Hashing " << item_ct << " items into " << buckets << " buckets" << std::endl;
    std::vector<std::string>::iterator vec_iter;
    int hashval(0);
    int highest_entry_count(0);
    for (vec_iter = to_hash.begin(); vec_iter != to_hash.end(); vec_iter++){
        hashval = myhash((*vec_iter).c_str(), pow_base, buckets);

        // See if exists
        map_iter = map.find(hashval);
        if (map_iter == map.end()){
            // Does not exist, insert it
            map.insert(mappair(hashval, 1));
        } else {
            // Does exist, construct new value and replace
            if (map_iter->second+1 > highest_entry_count){
                highest_entry_count = map_iter->second+1;
            }
            mappair newval(hashval, map_iter->second+1);
            map.erase(map_iter);
            map.insert(newval);
        }

        // Keep an ordered set of the hash buckets as well
        // Allows us to pretty print buckets in ascending order
        unique_buckets.insert(hashval);
    }
    
    // Now we can print out and analyze our distribution
    std::set<int>::iterator bucket_iter;
    bucket_iter = unique_buckets.begin();
    char pos_ind;

    while (bucket_iter != unique_buckets.end()){
        
        map_iter = map.find(*bucket_iter);
        if (map_iter != map.end()){
            if (map_iter->second > expected_bucket_size){
                pos_ind = '+';
            } else { 
                pos_ind = '-';
            }
            std::cout << "Bucket " << std::setw(floor(log10(buckets)+1)) << *bucket_iter << " contains " 
                      << std::setw(floor(log10(item_ct)+1)) << map_iter->second << " elements " 
                      << "(" << pos_ind << std::setw(4) << std::abs(map_iter->second-expected_bucket_size)
                      << ", " << pos_ind << std::setw(2) 
                      << (int)((std::abs((float)map_iter->second-expected_bucket_size)/expected_bucket_size)*100) << "%)\n";
        }

        bucket_iter++;
    }


    return 0;
}
