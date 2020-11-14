## Hashing project

This is just a small project to demonstrate hash buckets and the relatively uniform distribution that can be achieved with it. The purpose is pretty straightfoward: given `-n <number>` buckets and a list of words or alternatively a `-f <filename>` of words to hash, hash them into `n` buckets and print out how many objects each bucket contains and the percent difference from the number of objects each bucket _should_ have if objects were perfectly uniformly distributed.

What I've done to try to be clever is to initialize a vector of pointers to functions used to hash. So whenever you run this, you will execute all different hash algorithms defined and pushed into this vector in the `hash_functions.hh` source file. Simply define a new hash function, add it to the `hash_functions_vec_t* get_hash_functions(void)` function definition, recompile and run!

### Compiling
```shell
g++ [-g] -o hashpls main.cpp 
```

### Ideas

* Write multiple hash functions and dynamically use them based on another argument, or always run all defined functions and compare the variance of object count for each bucket for each algorithm

### Output

```shell
Hashing 1000 items into 10 buckets
Hashing with generic_hash...
Bucket  0 contains   98 elements (-   2, - 2%)
Bucket  1 contains   90 elements (-  10, -10%)
Bucket  2 contains  112 elements (+  12, +12%)
Bucket  3 contains   90 elements (-  10, -10%)
Bucket  4 contains  115 elements (+  15, +15%)
Bucket  5 contains   81 elements (-  19, -19%)
Bucket  6 contains  115 elements (+  15, +15%)
Bucket  7 contains   99 elements (-   1, - 1%)
Bucket  8 contains  121 elements (+  21, +21%)
Bucket  9 contains   79 elements (-  21, -21%)
Hashing with sum_and_mod...
Bucket  0 contains  107 elements (+   7, + 7%)
Bucket  1 contains   92 elements (-   8, - 8%)
Bucket  2 contains  106 elements (+   6, + 6%)
Bucket  3 contains   94 elements (-   6, - 6%)
Bucket  4 contains   94 elements (-   6, - 6%)
Bucket  5 contains  111 elements (+  11, +11%)
Bucket  6 contains  111 elements (+  11, +11%)
Bucket  7 contains  104 elements (+   4, + 4%)
Bucket  8 contains   82 elements (-  18, -18%)
Bucket  9 contains   99 elements (-   1, - 1%)
```
