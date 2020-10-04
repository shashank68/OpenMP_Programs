[Execution Times]

Serial: 439 microseconds
Parallel(8 threads): 179 microseconds

Performance decreases if executed with more than 8 threads (in a 8 logical core machine) as 
there will be races b/w threads and too many context switches