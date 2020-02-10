a) Iterations are picked based on the amount of time taken by the whole program. As we increased the number of objects time taken by program increased sigfinicantly from one run to next because objects are increasing with a factor of 2 in every run.
b) Time taken shown is the median over 5 runs with same number of objects and iterations. I choose median because it will help in eliminate the outlier that can skew the result in case of average.

Python benchmarks
=================
Objects              Iterations             Median Time Taken 
256                    10000                  0.37468375 us
512                    10000                  0.37787126953125 us
1024                   10000                  0.3783184375 us
2048                   10000                  0.39258639160156256 us
4096                   10000                  0.3819475 us
8192                   10000                  0.3889681103515625 us
16384                  1000                   0.3839431640625 us
32768                  1000                   0.3848013214111328 us
65536                  1000                   0.38387451171875 us
131072                 100                    0.38932688140869137 us
262144                 100                    0.3889594116210937 us
524288                 100                    0.3892770137786865 us
1048576                50                     0.4070401344299316 us
2097152                50                     0.399297574043274 us
4194304                20                     0.40324292421340946 us
8388608                20                     0.42920940518379214 us
16777216               10                     MemoryError

c++ benchmarks 
==============
Objects              Iterations             Median Time Taken 
256                    10000                  0.020053 us
512                    10000                  0.019558 us
1024                   10000                  0.019367 us
2048                   10000                  0.019269 us
4096                   10000                  0.020018 us
8192                   10000                  0.021741 us
16384                  10000                  0.020552 us
32768                  10000                  0.020874 us
65536                  10000                  0.021632 us
131072                 1000                   0.020485 us
262144                 1000                   0.020492 us
524288                 1000                   0.021834 us
1048576                500                    0.020082 us
2097152                100                    0.020623 us
4194304                100                    0.020684 us
8388608                100                    0.020596 us
16777216               50                     0.020226 us
