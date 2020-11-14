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
Hashing 100000 items into 10 buckets
Hashing with generic_hash...
Bucket  0 contains   9934 elements (-  66, - 0%)
Bucket  1 contains   9876 elements (- 124, - 1%)
Bucket  2 contains   9874 elements (- 126, - 1%)
Bucket  3 contains  10125 elements (+ 125, + 1%)
Bucket  4 contains   9998 elements (-   2, - 0%)
Bucket  5 contains  10207 elements (+ 207, + 2%)
Bucket  6 contains   9943 elements (-  57, - 0%)
Bucket  7 contains   9995 elements (-   5, - 0%)
Bucket  8 contains   9936 elements (-  64, - 0%)
Bucket  9 contains  10112 elements (+ 112, + 1%)
Hashing with sum_and_mod...
Bucket  0 contains  10084 elements (+  84, + 0%)
Bucket  1 contains   9865 elements (- 135, - 1%)
Bucket  2 contains  10104 elements (+ 104, + 1%)
Bucket  3 contains  10022 elements (+  22, + 0%)
Bucket  4 contains   9882 elements (- 118, - 1%)
Bucket  5 contains  10069 elements (+  69, + 0%)
Bucket  6 contains   9890 elements (- 110, - 1%)
Bucket  7 contains   9977 elements (-  23, - 0%)
Bucket  8 contains  10032 elements (+  32, + 0%)
Bucket  9 contains  10075 elements (+  75, + 0%)
```
