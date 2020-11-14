#ifndef HASH_FUNCTIONS_HH
#define HASH_FUNCTIONS_HH
// Implement a hash function

#include "math.h"
#include "string.h"

#include <string>
#include <utility>
#include <vector>

// pair of string, pointer to function returning int, accepting const char*, int, int
typedef std::pair<std::string, int(*)(const char*, int, int)> name_func_pair_t;
typedef std::vector<name_func_pair_t> hash_functions_vec_t;

int generic_hash(const char* str, int max_buckets, int pow_base = 153){
    
    const int len = strlen(str);
    long hash = 0;
    for (int i = 0; i < len; i++){
        hash += (long)pow(pow_base, len - (i+1)) * str[i];
        hash %= max_buckets;
    }

    return hash;
}

int sum_and_mod(const char* str, int max_buckets, int pow_base = 153){
    
    const int len = strlen(str);
    long hash = 0;
    for (int i = 0; i < len; i++){
        hash += (int)(str[i]);
        hash %= max_buckets;
    }

    return hash;
}

hash_functions_vec_t* get_hash_functions(void){
    
    hash_functions_vec_t* hfptr = new hash_functions_vec_t;
    hfptr->push_back(name_func_pair_t("generic_hash", &generic_hash));
    hfptr->push_back(name_func_pair_t("sum_and_mod", &sum_and_mod));

    return hfptr;

}

#endif
