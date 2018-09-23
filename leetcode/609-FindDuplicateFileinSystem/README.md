## Solution explanation

This is actually an phone interview I just did with George Caley@Dropbox. Several key points:

- Implement your own DFS search to get all the file path
- Implement dictionary with MD5 as key
- Identify the bottleneck in the place of calculating MD5
- Improve the performance of algorithm by first categorize the files based on the file size and
then build the hash map within each category

## Optimization

 In a real life solution
we will not hash the entire file content, since it's not practical.
Instead we first group the files with the same size together (in DFS).
Files with different sizes are guaranteed to be different.
We will then hash a small part of the files with equal sizes (using MD5 for example), which
will further filter out different files.
Only if the md5 is the same, we will hash the file content, which has
lower probability to happen after two filters above and even lower compared
with hashing every file content.

Hash can still have a chance that two different files with the same hash value.
To make sure the duplicated files we find are not false positive,
we can compare byte by byte instead of calculating hash in the last filtering step.

## Reference

- http://www.1point3acres.com/bbs/thread-172769-1-1.html
- https://leetcode.com/problems/find-duplicate-file-in-system/discuss/104123/C%2B%2B-clean-solution-answers-to-follow-up