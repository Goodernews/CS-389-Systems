# HW 9: Memory Coding Communtication (Evaluation Assignment)

## Question 1: Benchmarking the hierarchy 

This file

### Testing

To test, run `make run_benchmark` this will build `Benchmark` then create a file that times a list up to 1 gb by powers of 2 and makes 10,000 accesses to the memory. It then generates a plot in gnuplot.

## Analysis

This is a difficult assignment to avoid adding additional overhead to the timing. Some solutions I have heard have been to use a for loop (this creates additional micro instructions), unroll a for loop. I opted unroll a for loop into four calls and divide the time by four. 

[Graph of plot](plot.png)

*The resulting graph is chaotic and as of this commit is a point plot without fancy tricks. I have attempted to make it a boxplot or a graph with the x axis jittered to to no available.* 

My computer has the following memory hierarchy:
Location | Type | Size
---------|------|------
CPU | L1 Cache | 320 KB
CPU | L2 Cache | 2.0 MB
CPU | L3 Cache | 8.0 MB
RAM | RAM | 32 GB
Disk | SSD | 512 GB 
GPU | GPU | 6 GB


What I can say from this graph is there are a handful of outliers before 33 KB that continues to 128 kB. I would guess that at this stage it was still utulizing L1 cache as it had consistent fast results with the majority of points being negligible to time. 

From 512 kB to 2 MB (with the exception of 1 MB) there is a similar spread for the hits. 

After 2 MB there is no clear deliniation without becoming a [Texas Sharpshooter](https://en.wikipedia.org/wiki/Texas_sharpshooter_fallacy). There is a larger miss penalty at these figures. 

It's a little difficult to see because of the scaling, but once the computer is attempting to access from a gigabyte large array it has longer misses. 


Digging through the CSV, what is not reflected in this graph are the number of points where there exists overlap. In thelower ranges the time is closer to negligible. 
