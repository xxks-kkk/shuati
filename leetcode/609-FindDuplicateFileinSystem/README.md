## Solution explanation

This is actually an phone interview I just did with George Caley@Dropbox. Several key points:

- Implement your own DFS search to get all the file path
- Implement dictionary with MD5 as key
- Identify the bottleneck in the place of calculating MD5
- Improve the performance of algorithm by first categorize the files based on the file size and
then build the hash map within each category

## Reference

- http://www.1point3acres.com/bbs/thread-172769-1-1.html