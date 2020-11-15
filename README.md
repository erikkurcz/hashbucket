## Hashing project

This is just a small project to demonstrate hash buckets and the relatively uniform distribution that can be achieved with it. The purpose is pretty straightforward: given `-n <number>` buckets and a list of words or alternatively a `-f <filename>` of words to hash, hash them into `n` buckets and print out how many objects each bucket contains and the percent difference from the number of objects each bucket _should_ have if objects were perfectly uniformly distributed.

What I've done to try to be clever is to initialize a vector of pointers to functions used to hash. So whenever you run this, you will execute all different hash algorithms defined and pushed into this vector in the `hash_functions.hh` source file. Simply define a new hash function, add it to the `hash_functions_vec_t* get_hash_functions(void)` function definition, recompile and run!

Note that the `words.gz` file can be unzipped using `gunzip words.gz`, and it is 100,000 randomly generated character strings of length 1-100. I generated this as a larger sample of possible values, even if they aren't all that likely in the real world.

### Compiling
```shell
g++ [-g] -o hashpls main.cpp 
```

### `-g` option

This option is used to generate some somewhat random data like disk usage and query load. 10% of objects are generated with very skewed numbers just to make it a little more realistic, the point is to see that after hashing, and even with some pretty significant skew, the disk usage and query load across a given bucket is relatively homogeneous with other peers created by the same bucketing algorithm. This is still relatively high level, and median may be a better measure. And the way I calculated and stored the stats is abhorrent from clean code and RAM usage standpoint, but the point is, heterogeneous data can be uniformly distributed with a (or any of several) hashing algorithms to create homogeneous attributes at the per-bucket level.

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
Hashing with mod_the_first...
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
Hash function: generic_hash stats:
	Bucket: 0 avg disk: 25201.8, avg query: 5438.46
	Bucket: 1 avg disk: 25113.6, avg query: 5510.58
	Bucket: 2 avg disk: 25298.4, avg query: 5516.56
	Bucket: 3 avg disk: 24979.4, avg query: 5401.64
	Bucket: 4 avg disk: 25158.2, avg query: 5478.35
	Bucket: 5 avg disk: 25427.3, avg query: 5494.49
	Bucket: 6 avg disk: 25410.9, avg query: 5589.54
	Bucket: 7 avg disk: 25682.8, avg query: 5560.78
	Bucket: 8 avg disk: 25606.8, avg query: 5571.21
	Bucket: 9 avg disk: 25553.1, avg query: 5506.81
	Bucket: 10 avg disk: 25156.6, avg query: 5429.08
	Bucket: 11 avg disk: 25152.9, avg query: 5472.59
	Bucket: 12 avg disk: 25505.6, avg query: 5472.39
	Bucket: 13 avg disk: 25069.4, avg query: 5486.46
	Bucket: 14 avg disk: 25075.2, avg query: 5539.8
	Bucket: 15 avg disk: 24897.1, avg query: 5562.11
	Bucket: 16 avg disk: 25375.1, avg query: 5503.65
	Bucket: 17 avg disk: 25081.5, avg query: 5471.27
	Bucket: 18 avg disk: 25248.5, avg query: 5525.46
	Bucket: 19 avg disk: 24993.2, avg query: 5563.36
	Bucket: 20 avg disk: 24915.7, avg query: 5472.35
	Bucket: 21 avg disk: 25527.6, avg query: 5489.24
	Bucket: 22 avg disk: 25382.8, avg query: 5550.64
	Bucket: 23 avg disk: 25110.6, avg query: 5497.33
	Bucket: 24 avg disk: 25006.2, avg query: 5477
	Bucket: 25 avg disk: 25037.8, avg query: 5436.32
	Bucket: 26 avg disk: 25537.3, avg query: 5457.46
	Bucket: 27 avg disk: 25515.7, avg query: 5507.82
	Bucket: 28 avg disk: 24934.9, avg query: 5498.58
	Bucket: 29 avg disk: 25081.6, avg query: 5518.44
Hash function: sum_and_mod stats:
	Bucket: 0 avg disk: 25417.1, avg query: 5460.87
	Bucket: 1 avg disk: 25118.1, avg query: 5517.31
	Bucket: 2 avg disk: 25326.9, avg query: 5506.71
	Bucket: 3 avg disk: 25015.4, avg query: 5507.65
	Bucket: 4 avg disk: 25358.3, avg query: 5516.16
	Bucket: 5 avg disk: 25264.3, avg query: 5529.39
	Bucket: 6 avg disk: 24928.9, avg query: 5489.38
	Bucket: 7 avg disk: 24958.7, avg query: 5510.93
	Bucket: 8 avg disk: 25312, avg query: 5462.55
	Bucket: 9 avg disk: 25548.7, avg query: 5501.36
	Bucket: 10 avg disk: 25141.2, avg query: 5530.35
	Bucket: 11 avg disk: 25151.8, avg query: 5506.27
	Bucket: 12 avg disk: 25116.8, avg query: 5563.11
	Bucket: 13 avg disk: 25399.5, avg query: 5524.73
	Bucket: 14 avg disk: 25360.4, avg query: 5557.81
	Bucket: 15 avg disk: 24822, avg query: 5474.9
	Bucket: 16 avg disk: 25439.5, avg query: 5418.85
	Bucket: 17 avg disk: 25043.3, avg query: 5482.58
	Bucket: 18 avg disk: 25098.7, avg query: 5533.65
	Bucket: 19 avg disk: 25263.1, avg query: 5430.42
	Bucket: 20 avg disk: 24648.1, avg query: 5456.49
	Bucket: 21 avg disk: 25029.9, avg query: 5499.19
	Bucket: 22 avg disk: 25226.5, avg query: 5514.77
	Bucket: 23 avg disk: 25487.3, avg query: 5443.51
	Bucket: 24 avg disk: 25503.2, avg query: 5568.35
	Bucket: 25 avg disk: 25300.2, avg query: 5519.17
	Bucket: 26 avg disk: 25693.7, avg query: 5510.21
	Bucket: 27 avg disk: 25342.2, avg query: 5453.81
	Bucket: 28 avg disk: 25624.3, avg query: 5487.23
	Bucket: 29 avg disk: 25060.3, avg query: 5521.8
Hash function: sum_and_mod_at_end stats:
	Bucket: 0 avg disk: 25417.1, avg query: 5460.87
	Bucket: 1 avg disk: 25118.1, avg query: 5517.31
	Bucket: 2 avg disk: 25326.9, avg query: 5506.71
	Bucket: 3 avg disk: 25015.4, avg query: 5507.65
	Bucket: 4 avg disk: 25358.3, avg query: 5516.16
	Bucket: 5 avg disk: 25264.3, avg query: 5529.39
	Bucket: 6 avg disk: 24928.9, avg query: 5489.38
	Bucket: 7 avg disk: 24958.7, avg query: 5510.93
	Bucket: 8 avg disk: 25312, avg query: 5462.55
	Bucket: 9 avg disk: 25548.7, avg query: 5501.36
	Bucket: 10 avg disk: 25141.2, avg query: 5530.35
	Bucket: 11 avg disk: 25151.8, avg query: 5506.27
	Bucket: 12 avg disk: 25116.8, avg query: 5563.11
	Bucket: 13 avg disk: 25399.5, avg query: 5524.73
	Bucket: 14 avg disk: 25360.4, avg query: 5557.81
	Bucket: 15 avg disk: 24822, avg query: 5474.9
	Bucket: 16 avg disk: 25439.5, avg query: 5418.85
	Bucket: 17 avg disk: 25043.3, avg query: 5482.58
	Bucket: 18 avg disk: 25098.7, avg query: 5533.65
	Bucket: 19 avg disk: 25263.1, avg query: 5430.42
	Bucket: 20 avg disk: 24648.1, avg query: 5456.49
	Bucket: 21 avg disk: 25029.9, avg query: 5499.19
	Bucket: 22 avg disk: 25226.5, avg query: 5514.77
	Bucket: 23 avg disk: 25487.3, avg query: 5443.51
	Bucket: 24 avg disk: 25503.2, avg query: 5568.35
	Bucket: 25 avg disk: 25300.2, avg query: 5519.17
	Bucket: 26 avg disk: 25693.7, avg query: 5510.21
	Bucket: 27 avg disk: 25342.2, avg query: 5453.81
	Bucket: 28 avg disk: 25624.3, avg query: 5487.23
	Bucket: 29 avg disk: 25060.3, avg query: 5521.8
Hash function: mod_sum_mod stats:
	Bucket: 0 avg disk: 25417.1, avg query: 5460.87
	Bucket: 1 avg disk: 25118.1, avg query: 5517.31
	Bucket: 2 avg disk: 25326.9, avg query: 5506.71
	Bucket: 3 avg disk: 25015.4, avg query: 5507.65
	Bucket: 4 avg disk: 25358.3, avg query: 5516.16
	Bucket: 5 avg disk: 25264.3, avg query: 5529.39
	Bucket: 6 avg disk: 24928.9, avg query: 5489.38
	Bucket: 7 avg disk: 24958.7, avg query: 5510.93
	Bucket: 8 avg disk: 25312, avg query: 5462.55
	Bucket: 9 avg disk: 25548.7, avg query: 5501.36
	Bucket: 10 avg disk: 25141.2, avg query: 5530.35
	Bucket: 11 avg disk: 25151.8, avg query: 5506.27
	Bucket: 12 avg disk: 25116.8, avg query: 5563.11
	Bucket: 13 avg disk: 25399.5, avg query: 5524.73
	Bucket: 14 avg disk: 25360.4, avg query: 5557.81
	Bucket: 15 avg disk: 24822, avg query: 5474.9
	Bucket: 16 avg disk: 25439.5, avg query: 5418.85
	Bucket: 17 avg disk: 25043.3, avg query: 5482.58
	Bucket: 18 avg disk: 25098.7, avg query: 5533.65
	Bucket: 19 avg disk: 25263.1, avg query: 5430.42
	Bucket: 20 avg disk: 24648.1, avg query: 5456.49
	Bucket: 21 avg disk: 25029.9, avg query: 5499.19
	Bucket: 22 avg disk: 25226.5, avg query: 5514.77
	Bucket: 23 avg disk: 25487.3, avg query: 5443.51
	Bucket: 24 avg disk: 25503.2, avg query: 5568.35
	Bucket: 25 avg disk: 25300.2, avg query: 5519.17
	Bucket: 26 avg disk: 25693.7, avg query: 5510.21
	Bucket: 27 avg disk: 25342.2, avg query: 5453.81
	Bucket: 28 avg disk: 25624.3, avg query: 5487.23
	Bucket: 29 avg disk: 25060.3, avg query: 5521.8
Hash function: mod_sum_mod_every_other stats:
	Bucket: 0 avg disk: 25537.4, avg query: 5515.46
	Bucket: 1 avg disk: 25186.3, avg query: 5509.04
	Bucket: 2 avg disk: 25269.7, avg query: 5425.05
	Bucket: 3 avg disk: 25461.8, avg query: 5541.32
	Bucket: 4 avg disk: 25636.5, avg query: 5520.39
	Bucket: 5 avg disk: 25142, avg query: 5531.11
	Bucket: 6 avg disk: 25076.4, avg query: 5493.22
	Bucket: 7 avg disk: 24920.3, avg query: 5523.03
	Bucket: 8 avg disk: 25414.4, avg query: 5507.66
	Bucket: 9 avg disk: 25119.8, avg query: 5449.66
	Bucket: 10 avg disk: 24974.3, avg query: 5499.63
	Bucket: 11 avg disk: 25425.3, avg query: 5490.85
	Bucket: 12 avg disk: 25242, avg query: 5510.11
	Bucket: 13 avg disk: 25090.5, avg query: 5478.19
	Bucket: 14 avg disk: 24650.5, avg query: 5562.56
	Bucket: 15 avg disk: 25514.8, avg query: 5533.46
	Bucket: 16 avg disk: 25108.2, avg query: 5502.78
	Bucket: 17 avg disk: 25435.1, avg query: 5466.79
	Bucket: 18 avg disk: 24959.6, avg query: 5555.08
	Bucket: 19 avg disk: 25429.7, avg query: 5464.82
	Bucket: 20 avg disk: 25140.2, avg query: 5512.92
	Bucket: 21 avg disk: 25084.3, avg query: 5482.59
	Bucket: 22 avg disk: 25402.8, avg query: 5519.4
	Bucket: 23 avg disk: 25178.3, avg query: 5500.94
	Bucket: 24 avg disk: 25824, avg query: 5496.23
	Bucket: 25 avg disk: 24973.5, avg query: 5441.24
	Bucket: 26 avg disk: 25300.2, avg query: 5488.03
	Bucket: 27 avg disk: 25103.7, avg query: 5565.08
	Bucket: 28 avg disk: 25469.3, avg query: 5436.16
	Bucket: 29 avg disk: 24907.9, avg query: 5475.75
Hash function: mod_the_first stats:
	Bucket: 0 avg disk: 25184.9, avg query: 5510.98
	Bucket: 1 avg disk: 25046.9, avg query: 5570.07
	Bucket: 2 avg disk: 24720.1, avg query: 5515.44
	Bucket: 7 avg disk: 25098.3, avg query: 5505.79
	Bucket: 8 avg disk: 25297.3, avg query: 5518.04
	Bucket: 9 avg disk: 25381.1, avg query: 5517.78
	Bucket: 10 avg disk: 25657.3, avg query: 5494.57
	Bucket: 11 avg disk: 25171.7, avg query: 5424.35
	Bucket: 12 avg disk: 25227.7, avg query: 5495.48
	Bucket: 13 avg disk: 25237.1, avg query: 5474.33
	Bucket: 14 avg disk: 25102.2, avg query: 5476.73
	Bucket: 15 avg disk: 25289.8, avg query: 5443.81
	Bucket: 16 avg disk: 25093.2, avg query: 5527.54
	Bucket: 17 avg disk: 25172.2, avg query: 5546.72
	Bucket: 18 avg disk: 24989.3, avg query: 5501.82
	Bucket: 19 avg disk: 25173.1, avg query: 5489.04
	Bucket: 20 avg disk: 24968.8, avg query: 5489.92
	Bucket: 21 avg disk: 25491.6, avg query: 5417.67
	Bucket: 22 avg disk: 25438.2, avg query: 5508.73
	Bucket: 23 avg disk: 25395.3, avg query: 5463.1
	Bucket: 24 avg disk: 25481.6, avg query: 5506.16
	Bucket: 25 avg disk: 25169.2, avg query: 5588.69
	Bucket: 26 avg disk: 25370, avg query: 5451.17
	Bucket: 27 avg disk: 25478.2, avg query: 5511.41
	Bucket: 28 avg disk: 25515.7, avg query: 5514.41
	Bucket: 29 avg disk: 24961.1, avg query: 5536.08
```
