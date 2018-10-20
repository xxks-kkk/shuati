# External GroupBy

### Problem Statement

The goal of this assignment is to implement a program which can group a collection of key-value pairs by their keys. The program will combine all values in sorted order associated with a key, and return the resulting keys in sorted order.
The program will take a memory limit as input as well as the key-value pairs from stdin. It should write the output (key, sorted list of values) in stdout. The function should work even if the input size exceeds the size of memory.

As an example:

input (stdin)
```
1000000
a y
b x
a z
```

expected output (stdout)
```
a y z
b x
```

### Requirements

- The first number in the input size represents the maximal amount of memory that can be used (in bytes). Your program should work even if the total size of input exceeds that memory.
- The memory limit is not a hard requirement. You can use extra memory as long as the extra memory consumption is a reasonable constant that is independent of the input.
- Your algorithm should not exceed `O(n log n)` average case performance for n input key-value pairs and it should not be clearly inefficient. However, you should not worry about optimizing the performance beyond this (e.g. data compression is not necessary).
- Your implementation should be production-ready. We recommend writing your own tests.
- Please provid instructions (e.g. a script) on how to build and test the code.
- Plese write a small doc to describe your algorithm, complexity and code structure to help reviewer understand your code.

### Assumptions and Clarifications

- The keys and values are both strings (but with no constraint on length).
- For the purposes of memory management, you can assume a string of `n` characters takes up `n + 1` bytes.
- You may assume that the total size of all values for any one key will fit in memory. However, the set of all distinct keys may not fit in memory.
- You can create files to store intermediate data, but the number of files you use should not be linear to the number of distinct keys.
- Please minimize external dependencies. If you want to use external libraries, please provide build file and script for running it.
- Please do not use 3rd party databases, such as `sqlite`, `rocksdb`, `redis`, and others that implement a database `groupBy` method.

### Tests

To make it easy to work on the solution, we provide scripts for testing your program.

Run brute force solution included in this package
```
$ scripts/run_test.sh scripts/brute_force.py
Test finished successfully! Peak memory usage was 68888 kilobytes.
```

Run a wrong solution using system command `cat`
```
$ scripts/run_test.sh cat
Test failed! Peak memory usage was 768 kilobytes.
```

* Please note that the test script is included for convenience purpose. We will run more complicated tests on your solution.

### Submission

After completion of the assignment, please zip the folder containing your source code and tests, and email us the zip file as your submission.
Please do NOT upload the assignment or your submission to any public location.
