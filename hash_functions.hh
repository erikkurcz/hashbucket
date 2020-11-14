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

int sum_and_mod_at_end(const char* str, int max_buckets, int pow_base = 153){

    const int len = strlen(str);
    long hash = 0;
    for (int i = 0; i < len; i++){
        hash += (int)(str[i]);
    }

    return hash % max_buckets;
}

int mod_sum_mod(const char* str, int max_buckets, int pow_base = 153){

    const int len = strlen(str);
    long hash = 0;
    for (int i = 0; i < len; i++){
        hash += (int)(str[i]) % max_buckets;
    }

    return hash % max_buckets;
}

int mod_sum_mod_every_other(const char* str, int max_buckets, int pow_base = 153){

    const int len = strlen(str);
    long hash = 0;
    for (int i = 0; i < len; i++){
        hash += (int)(str[i]) % max_buckets;
        i++; // every other
    }

    return hash % max_buckets;
}

int mod_the_first(const char* str, int max_buckets, int pow_base = 153){
    // Expecting poor performance here, should only put into 26 buckets
    const int len = strlen(str);
    long hash = (int)(str[0]) % max_buckets;

    return hash;
}

hash_functions_vec_t* get_hash_functions(void){
    
    hash_functions_vec_t* hfptr = new hash_functions_vec_t;
    hfptr->push_back(name_func_pair_t("generic_hash", &generic_hash));
    hfptr->push_back(name_func_pair_t("sum_and_mod", &sum_and_mod));
    hfptr->push_back(name_func_pair_t("sum_and_mod_at_end", &sum_and_mod_at_end));
    hfptr->push_back(name_func_pair_t("mod_sum_mod", &mod_sum_mod));
    hfptr->push_back(name_func_pair_t("mod_sum_mod_every_other", &mod_sum_mod_every_other));
    hfptr->push_back(name_func_pair_t("mod_the_first", &mod_the_first));

    return hfptr;

}

#endif
