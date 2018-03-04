## Solution explanation

做法就是找到根节点，然后往下遍历，把自己的membershipList传下去，子节点如果自己是share的，
就把父节点传来的membershipList的cows都加到自己里面。
到叶子节点的时候记录下其membershipList里的cow能够access这个节点了，然后遍历所有cow，
哪些access节点数目不等于总叶子数，就是不能access所有节点的.

## Reference

- http://www.1point3acres.com/bbs/thread-290502-1-1.html
- http://www.1point3acres.com/bbs/thread-319691-1-1.html