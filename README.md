## Hashing project

This is just a small project to demonstrate hash buckets and the relatively uniform distribution that can be achieved with it. The purpose is pretty straightforward: given `-n <number>` buckets and a list of words or alternatively a `-f <filename>` of words to hash, hash them into `n` buckets and print out how many objects each bucket contains and the percent difference from the number of objects each bucket _should_ have if objects were perfectly uniformly distributed.

What I've done to try to be clever is to initialize a vector of pointers to functions used to hash. So whenever you run this, you will execute all different hash algorithms defined and pushed into this vector in the `hash_functions.hh` source file. Simply define a new hash function, add it to the `hash_functions_vec_t* get_hash_functions(void)` function definition, recompile and run!

Note that the `words.gz` file can be unzipped using `gunzip words.gz`, and it is 100,000 randomly generated character strings of length 1-100. I generated this as a larger sample of possible values, even if they aren't all that likely in the real world.

### Compiling
```shell
g++ [-g] -o hashpls main.cpp 
```

### Ideas

* Write multiple hash functions and dynamically use them based on another argument, or always run all defined functions and compare the variance of object count for each bucket for each algorithm

### Output

```shell
Hashing 100000 items into 30 buckets
Hashing with generic_hash...
Bucket  0 contains   3312 elements (-  21, - 0%)
Bucket  1 contains   3222 elements (- 111, - 3%)
Bucket  2 contains   3287 elements (-  46, - 1%)
Bucket  3 contains   3334 elements (+   1, + 0%)
Bucket  4 contains   3373 elements (+  40, + 1%)
Bucket  5 contains   3381 elements (+  48, + 1%)
Bucket  6 contains   3212 elements (- 121, - 3%)
Bucket  7 contains   3349 elements (+  16, + 0%)
Bucket  8 contains   3378 elements (+  45, + 1%)
Bucket  9 contains   3325 elements (-   8, - 0%)
Bucket 10 contains   3266 elements (-  67, - 2%)
Bucket 11 contains   3379 elements (+  46, + 1%)
Bucket 12 contains   3312 elements (-  21, - 0%)
Bucket 13 contains   3391 elements (+  58, + 1%)
Bucket 14 contains   3336 elements (+   3, + 0%)
Bucket 15 contains   3463 elements (+ 130, + 3%)
Bucket 16 contains   3336 elements (+   3, + 0%)
Bucket 17 contains   3385 elements (+  52, + 1%)
Bucket 18 contains   3291 elements (-  42, - 1%)
Bucket 19 contains   3338 elements (+   5, + 0%)
Bucket 20 contains   3356 elements (+  23, + 0%)
Bucket 21 contains   3275 elements (-  58, - 1%)
Bucket 22 contains   3275 elements (-  58, - 1%)
Bucket 23 contains   3400 elements (+  67, + 2%)
Bucket 24 contains   3289 elements (-  44, - 1%)
Bucket 25 contains   3363 elements (+  30, + 0%)
Bucket 26 contains   3395 elements (+  62, + 1%)
Bucket 27 contains   3261 elements (-  72, - 2%)
Bucket 28 contains   3267 elements (-  66, - 1%)
Bucket 29 contains   3449 elements (+ 116, + 3%)
Hashing with sum_and_mod...
Bucket  0 contains   3353 elements (+  20, + 0%)
Bucket  1 contains   3229 elements (- 104, - 3%)
Bucket  2 contains   3339 elements (+   6, + 0%)
Bucket  3 contains   3298 elements (-  35, - 1%)
Bucket  4 contains   3259 elements (-  74, - 2%)
Bucket  5 contains   3341 elements (+   8, + 0%)
Bucket  6 contains   3255 elements (-  78, - 2%)
Bucket  7 contains   3342 elements (+   9, + 0%)
Bucket  8 contains   3281 elements (-  52, - 1%)
Bucket  9 contains   3354 elements (+  21, + 0%)
Bucket 10 contains   3377 elements (+  44, + 1%)
Bucket 11 contains   3391 elements (+  58, + 1%)
Bucket 12 contains   3440 elements (+ 107, + 3%)
Bucket 13 contains   3355 elements (+  22, + 0%)
Bucket 14 contains   3353 elements (+  20, + 0%)
Bucket 15 contains   3370 elements (+  37, + 1%)
Bucket 16 contains   3341 elements (+   8, + 0%)
Bucket 17 contains   3321 elements (-  12, - 0%)
Bucket 18 contains   3311 elements (-  22, - 0%)
Bucket 19 contains   3379 elements (+  46, + 1%)
Bucket 20 contains   3354 elements (+  21, + 0%)
Bucket 21 contains   3245 elements (-  88, - 2%)
Bucket 22 contains   3325 elements (-   8, - 0%)
Bucket 23 contains   3369 elements (+  36, + 1%)
Bucket 24 contains   3270 elements (-  63, - 1%)
Bucket 25 contains   3358 elements (+  25, + 0%)
Bucket 26 contains   3294 elements (-  39, - 1%)
Bucket 27 contains   3314 elements (-  19, - 0%)
Bucket 28 contains   3440 elements (+ 107, + 3%)
Bucket 29 contains   3342 elements (+   9, + 0%)
Hashing with sum_and_mod_at_end...
Bucket  0 contains   3353 elements (+  20, + 0%)
Bucket  1 contains   3229 elements (- 104, - 3%)
Bucket  2 contains   3339 elements (+   6, + 0%)
Bucket  3 contains   3298 elements (-  35, - 1%)
Bucket  4 contains   3259 elements (-  74, - 2%)
Bucket  5 contains   3341 elements (+   8, + 0%)
Bucket  6 contains   3255 elements (-  78, - 2%)
Bucket  7 contains   3342 elements (+   9, + 0%)
Bucket  8 contains   3281 elements (-  52, - 1%)
Bucket  9 contains   3354 elements (+  21, + 0%)
Bucket 10 contains   3377 elements (+  44, + 1%)
Bucket 11 contains   3391 elements (+  58, + 1%)
Bucket 12 contains   3440 elements (+ 107, + 3%)
Bucket 13 contains   3355 elements (+  22, + 0%)
Bucket 14 contains   3353 elements (+  20, + 0%)
Bucket 15 contains   3370 elements (+  37, + 1%)
Bucket 16 contains   3341 elements (+   8, + 0%)
Bucket 17 contains   3321 elements (-  12, - 0%)
Bucket 18 contains   3311 elements (-  22, - 0%)
Bucket 19 contains   3379 elements (+  46, + 1%)
Bucket 20 contains   3354 elements (+  21, + 0%)
Bucket 21 contains   3245 elements (-  88, - 2%)
Bucket 22 contains   3325 elements (-   8, - 0%)
Bucket 23 contains   3369 elements (+  36, + 1%)
Bucket 24 contains   3270 elements (-  63, - 1%)
Bucket 25 contains   3358 elements (+  25, + 0%)
Bucket 26 contains   3294 elements (-  39, - 1%)
Bucket 27 contains   3314 elements (-  19, - 0%)
Bucket 28 contains   3440 elements (+ 107, + 3%)
Bucket 29 contains   3342 elements (+   9, + 0%)
Hashing with mod_sum_mod...
Bucket  0 contains   3353 elements (+  20, + 0%)
Bucket  1 contains   3229 elements (- 104, - 3%)
Bucket  2 contains   3339 elements (+   6, + 0%)
Bucket  3 contains   3298 elements (-  35, - 1%)
Bucket  4 contains   3259 elements (-  74, - 2%)
Bucket  5 contains   3341 elements (+   8, + 0%)
Bucket  6 contains   3255 elements (-  78, - 2%)
Bucket  7 contains   3342 elements (+   9, + 0%)
Bucket  8 contains   3281 elements (-  52, - 1%)
Bucket  9 contains   3354 elements (+  21, + 0%)
Bucket 10 contains   3377 elements (+  44, + 1%)
Bucket 11 contains   3391 elements (+  58, + 1%)
Bucket 12 contains   3440 elements (+ 107, + 3%)
Bucket 13 contains   3355 elements (+  22, + 0%)
Bucket 14 contains   3353 elements (+  20, + 0%)
Bucket 15 contains   3370 elements (+  37, + 1%)
Bucket 16 contains   3341 elements (+   8, + 0%)
Bucket 17 contains   3321 elements (-  12, - 0%)
Bucket 18 contains   3311 elements (-  22, - 0%)
Bucket 19 contains   3379 elements (+  46, + 1%)
Bucket 20 contains   3354 elements (+  21, + 0%)
Bucket 21 contains   3245 elements (-  88, - 2%)
Bucket 22 contains   3325 elements (-   8, - 0%)
Bucket 23 contains   3369 elements (+  36, + 1%)
Bucket 24 contains   3270 elements (-  63, - 1%)
Bucket 25 contains   3358 elements (+  25, + 0%)
Bucket 26 contains   3294 elements (-  39, - 1%)
Bucket 27 contains   3314 elements (-  19, - 0%)
Bucket 28 contains   3440 elements (+ 107, + 3%)
Bucket 29 contains   3342 elements (+   9, + 0%)
Hashing with mod_sum_mod_every_other...
Bucket  0 contains   3389 elements (+  56, + 1%)
Bucket  1 contains   3278 elements (-  55, - 1%)
Bucket  2 contains   3314 elements (-  19, - 0%)
Bucket  3 contains   3319 elements (-  14, - 0%)
Bucket  4 contains   3331 elements (-   2, - 0%)
Bucket  5 contains   3253 elements (-  80, - 2%)
Bucket  6 contains   3259 elements (-  74, - 2%)
Bucket  7 contains   3236 elements (-  97, - 2%)
Bucket  8 contains   3466 elements (+ 133, + 3%)
Bucket  9 contains   3327 elements (-   6, - 0%)
Bucket 10 contains   3418 elements (+  85, + 2%)
Bucket 11 contains   3292 elements (-  41, - 1%)
Bucket 12 contains   3413 elements (+  80, + 2%)
Bucket 13 contains   3423 elements (+  90, + 2%)
Bucket 14 contains   3265 elements (-  68, - 2%)
Bucket 15 contains   3258 elements (-  75, - 2%)
Bucket 16 contains   3386 elements (+  53, + 1%)
Bucket 17 contains   3383 elements (+  50, + 1%)
Bucket 18 contains   3301 elements (-  32, - 0%)
Bucket 19 contains   3319 elements (-  14, - 0%)
Bucket 20 contains   3428 elements (+  95, + 2%)
Bucket 21 contains   3425 elements (+  92, + 2%)
Bucket 22 contains   3297 elements (-  36, - 1%)
Bucket 23 contains   3313 elements (-  20, - 0%)
Bucket 24 contains   3376 elements (+  43, + 1%)
Bucket 25 contains   3179 elements (- 154, - 4%)
Bucket 26 contains   3372 elements (+  39, + 1%)
Bucket 27 contains   3362 elements (+  29, + 0%)
Bucket 28 contains   3297 elements (-  36, - 1%)
Bucket 29 contains   3321 elements (-  12, - 0%)
Hashing with mod_the_first... **NOTE: only 26 buckets resulted, because this hash funtion only mods against a single character - buckets 3, 4, 5, and 6 are missing!. As a result, all buckets have 'too many' keys because there are 4 fewer actual buckets than were asked for (this run was -n 30)**
Bucket  0 contains   3806 elements (+ 473, +14%)
Bucket  1 contains   3750 elements (+ 417, +12%)
Bucket  2 contains   3933 elements (+ 600, +18%)
Bucket  7 contains   3922 elements (+ 589, +17%)
Bucket  8 contains   3887 elements (+ 554, +16%)
Bucket  9 contains   3903 elements (+ 570, +17%)
Bucket 10 contains   3872 elements (+ 539, +16%)
Bucket 11 contains   3848 elements (+ 515, +15%)
Bucket 12 contains   3857 elements (+ 524, +15%)
Bucket 13 contains   4070 elements (+ 737, +22%)
Bucket 14 contains   3850 elements (+ 517, +15%)
Bucket 15 contains   3806 elements (+ 473, +14%)
Bucket 16 contains   3964 elements (+ 631, +18%)
Bucket 17 contains   3863 elements (+ 530, +15%)
Bucket 18 contains   3863 elements (+ 530, +15%)
Bucket 19 contains   3895 elements (+ 562, +16%)
Bucket 20 contains   3814 elements (+ 481, +14%)
Bucket 21 contains   3741 elements (+ 408, +12%)
Bucket 22 contains   3667 elements (+ 334, +10%)
Bucket 23 contains   3897 elements (+ 564, +16%)
Bucket 24 contains   3780 elements (+ 447, +13%)
Bucket 25 contains   3790 elements (+ 457, +13%)
Bucket 26 contains   3817 elements (+ 484, +14%)
Bucket 27 contains   3846 elements (+ 513, +15%)
Bucket 28 contains   3722 elements (+ 389, +11%)
Bucket 29 contains   3837 elements (+ 504, +15%)
```
