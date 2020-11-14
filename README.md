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
Hashing 1000 items into 30 buckets
Hashing with generic_hash...
Bucket  0 contains   29 elements (-   4, -12%)
Bucket  1 contains   30 elements (-   3, - 9%)
Bucket  2 contains   49 elements (+  16, +48%)
Bucket  3 contains   28 elements (-   5, -15%)
Bucket  4 contains   42 elements (+   9, +27%)
Bucket  5 contains   31 elements (-   2, - 6%)
Bucket  6 contains   33 elements (-   0, - 0%)
Bucket  7 contains   30 elements (-   3, - 9%)
Bucket  8 contains   40 elements (+   7, +21%)
Bucket  9 contains   27 elements (-   6, -18%)
Bucket 10 contains   36 elements (+   3, + 9%)
Bucket 11 contains   29 elements (-   4, -12%)
Bucket 12 contains   29 elements (-   4, -12%)
Bucket 13 contains   26 elements (-   7, -21%)
Bucket 14 contains   35 elements (+   2, + 6%)
Bucket 15 contains   25 elements (-   8, -24%)
Bucket 16 contains   50 elements (+  17, +51%)
Bucket 17 contains   31 elements (-   2, - 6%)
Bucket 18 contains   41 elements (+   8, +24%)
Bucket 19 contains   30 elements (-   3, - 9%)
Bucket 20 contains   33 elements (-   0, - 0%)
Bucket 21 contains   31 elements (-   2, - 6%)
Bucket 22 contains   34 elements (+   1, + 3%)
Bucket 23 contains   36 elements (+   3, + 9%)
Bucket 24 contains   38 elements (+   5, +15%)
Bucket 25 contains   25 elements (-   8, -24%)
Bucket 26 contains   32 elements (-   1, - 3%)
Bucket 27 contains   38 elements (+   5, +15%)
Bucket 28 contains   40 elements (+   7, +21%)
Bucket 29 contains   22 elements (-  11, -33%)
Hashing with sum_and_mod...
Bucket  0 contains   36 elements (+   3, + 9%)
Bucket  1 contains   34 elements (+   1, + 3%)
Bucket  2 contains   39 elements (+   6, +18%)
Bucket  3 contains   34 elements (+   1, + 3%)
Bucket  4 contains   33 elements (-   0, - 0%)
Bucket  5 contains   41 elements (+   8, +24%)
Bucket  6 contains   40 elements (+   7, +21%)
Bucket  7 contains   31 elements (-   2, - 6%)
Bucket  8 contains   24 elements (-   9, -27%)
Bucket  9 contains   28 elements (-   5, -15%)
Bucket 10 contains   28 elements (-   5, -15%)
Bucket 11 contains   31 elements (-   2, - 6%)
Bucket 12 contains   36 elements (+   3, + 9%)
Bucket 13 contains   33 elements (-   0, - 0%)
Bucket 14 contains   31 elements (-   2, - 6%)
Bucket 15 contains   38 elements (+   5, +15%)
Bucket 16 contains   37 elements (+   4, +12%)
Bucket 17 contains   31 elements (-   2, - 6%)
Bucket 18 contains   23 elements (-  10, -30%)
Bucket 19 contains   45 elements (+  12, +36%)
Bucket 20 contains   43 elements (+  10, +30%)
Bucket 21 contains   27 elements (-   6, -18%)
Bucket 22 contains   31 elements (-   2, - 6%)
Bucket 23 contains   27 elements (-   6, -18%)
Bucket 24 contains   30 elements (-   3, - 9%)
Bucket 25 contains   32 elements (-   1, - 3%)
Bucket 26 contains   34 elements (+   1, + 3%)
Bucket 27 contains   42 elements (+   9, +27%)
Bucket 28 contains   35 elements (+   2, + 6%)
Bucket 29 contains   26 elements (-   7, -21%)
```
