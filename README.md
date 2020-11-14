## Hashing project

This is just a small project to demonstrate hash buckets and the relatively uniform distribution that can be achieved with it. Purpose is pretty straightfoward: given `-n <number>` buckets and a list of words or alternatively a `-f <filename>` of words to hash, hash them into `n` buckets and print out how many objects each bucket contains and the percent difference from the number of objects each bucket _should_ have if objects were perfectly uniformly distributed.

### Compiling
```shell
g++ [-g] -o hashpls main.cpp 
```

### Ideas

* Write multiple hash functions and dynamically use them based on another argument, or always run all defined functions and compare the variance of object count for each bucket for each algorithm

### Output

```shell
Hashing 100000 items into 27 buckets
Bucket  0 contains   3678 elements (-  25, - 0%)
Bucket  1 contains   3733 elements (+  30, + 0%)
Bucket  2 contains   3741 elements (+  38, + 1%)
Bucket  3 contains   3662 elements (-  41, - 1%)
Bucket  4 contains   3762 elements (+  59, + 1%)
Bucket  5 contains   3704 elements (+   1, + 0%)
Bucket  6 contains   3662 elements (-  41, - 1%)
Bucket  7 contains   3553 elements (- 150, - 4%)
Bucket  8 contains   3761 elements (+  58, + 1%)
Bucket  9 contains   3734 elements (+  31, + 0%)
Bucket 10 contains   3657 elements (-  46, - 1%)
Bucket 11 contains   3702 elements (-   1, - 0%)
Bucket 12 contains   3589 elements (- 114, - 3%)
Bucket 13 contains   3732 elements (+  29, + 0%)
Bucket 14 contains   3757 elements (+  54, + 1%)
Bucket 15 contains   3574 elements (- 129, - 3%)
Bucket 16 contains   3747 elements (+  44, + 1%)
Bucket 17 contains   3820 elements (+ 117, + 3%)
Bucket 18 contains   3655 elements (-  48, - 1%)
Bucket 19 contains   3696 elements (-   7, - 0%)
Bucket 20 contains   3727 elements (+  24, + 0%)
Bucket 21 contains   3772 elements (+  69, + 1%)
Bucket 22 contains   3723 elements (+  20, + 0%)
Bucket 23 contains   3785 elements (+  82, + 2%)
Bucket 24 contains   3748 elements (+  45, + 1%)
Bucket 25 contains   3577 elements (- 126, - 3%)
Bucket 26 contains   3749 elements (+  46, + 1%)
```
