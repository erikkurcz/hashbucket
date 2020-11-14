// Implement a hash function

#include "math.h"
#include "string.h"

int myhash(const char* str, int pow_base, int max_buckets){
    
    const int len = strlen(str);
    long hash = 0;
    for (int i = 0; i < len; i++){
        hash += (long)pow(pow_base, len - (i+1)) * str[i];
        hash %= max_buckets;
    }

    return hash;
}
