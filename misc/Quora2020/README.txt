# Quora 2020 New Grad OA

## add string digits

example:
input: a="19", b = "22"； output: "311" (9+2 = 11, 1+2=3)
input: a="20", b = "2032"; output: "2052"
注意是从后往前计算

## distinct triplet

example：
input：[1,3,2,4,4,5,6,7,8]; output: 5
意思就是三个连续的数字如果都是distinct就是distinct triplet，结果就要+1，直接brute force

## sort diagnal

v1: 沿着main diagonal的方向sort，top left to bottom right
v2: 说给一个matrix. matrix乱序。要把matrix 从左上角到右下角方向的所有平行对角线按照升序排序
v3: Given a matrix, sort the matrix based on the main diagonal (from top left to bottom right in ascending order) for every diagonal
Example: 中间 -》 （3，2） 换了， 右上角 -> (4， 2) 换了， 左下角 -》(7, 2) 换了
Input -> [
[1,4,7],
[7,3,2],
[5,2,2],
]

Output -> [
[1,2,7],
[2,2,4],
[5,7,3]
]

## GoodTuple

Give an array and find the count of a pair number and a single number combination in a row of this array. 
Target array is a[i - 1], a, a[i + 1]

Example：
- Input: a = [1, 1, 2, 1, 5, 3, 2, 3]
- Output: 3

Explain:
[1, 1, 2] -> two 1 and one 2(O)
[1, 2, 1] -> two 1 and one 2(O)
[2, 1, 5] -> one 2, one 1 and one five(X)
[1, 5, 3] -> (X)
[5, 3, 2] -> (X)
[3, 2, 3] -> (O)

## validLetters

之前面经有过的题。输入一组words和一组valid letters，判断有多少个words是valid。判断条件是words里的所有upper and lower letter必须在valid letters里面。
如果word里面有special character不用管。注意valid letter只有小写，但是words里面有大写的也算valid。比如words = [hEllo##, This^^],
valid letter = [h, e, l, 0, t, h, s]; "hello##" 就是valid，因为h，e，l，o都在valid letter 里面， “This^^” 不valid, 因为i不在valid letter里面

## Rotate matrix among Diagnals

转K次 但是 diag不转

Example：
[[1, 2, 3],
 [4, 5, 6],
 [7, 8, 9]]
-->
[[1, 4, 3],
 [8, 5, 2],
 [7, 6, 9]]
(k=1)

[ [1, 2, 3, 4, 5],
  [6, 7, 8, 9, 10],
  [11,12,13,14,15],
  [16,17,18,19,20],
  [21,22,23,24,25]]
-->
[ [1, 6,  11, 16,  5],
  [22, 7,  12, 9,  2],
  [23, 18, 13, 8,  3],
  [24, 17, 14, 19, 4],
  [21, 10, 15, 20, 25]]
(k=1)

Note: the rotation example may not match with actual problem

## Cut ribbon

剪缎带，给一个数组，里边的数值代表不同长度的缎带，要求最后剪出至少k段相同长度的缎带，返回剪完后的最大长度：
举例[1,2,3,4,9] k = 5
output: 3
explain：9可以剪成3截，4可以出一截，3可以出一截
这道题也很简单，直接二分拿下

Given a list representing the length of ribbon, and the target number "k" parts of ribbon.
we want to cut ribbon into k parts with the same size, at the same time we want the maximum size.

Ex.
Input: A = [1, 2, 3, 4, 9], k = 5
Output: 3

Explanation:
if size = 1, then we have 19 parts
if seize = 2, then we have 8 parts
if size = 3, then we have 5 parts
if size = 4, then we have 3 parts, which is not enough.
So return the max size = 3.

Sol.
Use b‍‌‌‍‌‌‍‍‍‌‌‌‍‌‌‌‌inary search to find the size of ribbon to reach the time limit.

## matrix sort

v1: 输入为n*n数字矩阵，要求其中数字按照出现频率升序排列，相同频率按照大小升序排列。比如 1 0 3 2 2 3  0 0 0，
排序后为1 2 2 3 3 0 0 0 0。 返回一个n*n矩阵，矩阵中的数字为排序后数字按照平行反对角线方向从右下到左上依次填充。
说的很难理解，看个例子：假设排序后数字为1 2 3 4 5 6 7 8 9，返回
9 7 4
8 5 2
6 3 1

## string close

If two strings are close enough.
Given two rules to define two strings are close enough.
1. you can swap neighbor char any times. Ex. "abb" -> "bba"
2. If two strings have the same character, then you can change the character into another.
    Ex. If both strings contain "a" and "b", you can change all "a"s in the first string or change all "b"s in the first string. same as the second string

Ex.
Input: S1 = "babzccc", S2 = "abbzczz"
Output: True

Sol.
Use a dictionary to record the frequency of characters.
Remove the same part in dictionaries
try to find the pair that have different character but with the same frequency

之前面经也出现过。compare两个string，只有小写字母。 每个stirng内部可以任意换位置，所以位置不重要。每个string内部两个letter出现的频率也可以互换，所以这题只需要两个string每个frequency出现的次数要一样。
比如“babzccc” 和 “bbazzcz” 就返回“true”，因为z和c可以互换频率。 但是“babzcccm” 和 “bbazzczl” 就不一样，因为m在第一个里出现过，第二个里没有出现过。

## queryFind.

input 1-D array, 2-D ‍‌‌‍‌‌‍‍‍‌‌‌‍‌‌‌‌array(query)，返回int 和地里其他人描述的一致，
就是query(l, r, num)找到在[l : r]之间的num个数，累加输出。这里[l : r]都是index从0开始

之前面经好像还是有。。输入a，b两个array， 一个query array。query有两种type， 一种是[target]查从a中‍‌‌‍‌‌‍‍‍‌‌‌‍‌‌‌‌取一个数，b中取一个数，
求加起来等于target的情况有多少种。第二种query是[index, num], 把b中在index位置的数字改成num，这种query不需要输出。最后输出所有第一种query的result。

## subset sum

给一个list求subset sum最大的方式， 不能同时包含两个数字相差等于1
eg.   [1, 1, 1, 2, 2, 3] -> 6‍‌‌‍‌‌‍‍‍‌‌‌‍‌‌‌‌
[1, 2, 2, 2, 2, 4] -> 12

## max Arithmetic Length

input A:[0, 4, 8, 16]
input B:[0, 2, 6, 12, 14, 20]
output: 新的A 的长度

从B中最多能选几个数字使得 A 变成一个任意两个数之间的差‍‌‌‍‌‌‍‍‍‌‌‌‍‌‌‌‌是相等的数组， 例如：[0, 4, 8, 12, 16, 20]
千年难题，还是不会

## divisor substring

Given an int `n` and int `k`, return the number of substring of `n` with length `k` that is divisor of `n`
(i.e., n % substring of `n` == 0)

e.g., n = 120, k = 2, then return 2 because "120" substring with length 2 is "12", "20" and both of them are divisors

## Divide array

Given an array, divide it into two equal length subarray. return empty array if no such division exists

## Cool feature

given `vector<int> a`, `vector<int> b`, and `vector<vector<int>> query`:

- `query` is a collection of queries of two forms:
  - [0,i,x] means assign b[i] with x
  - [1,x] means find all pairs of a[i] and b[j] such that a[i]+b[j] = x; return the number of such pairs

e.g., a = [1,2,3], b = [3,4], query = [[1,5],[0,0,1],[1,5]] return [2,1]
      a = [1,2,2], b = [2,3], query = [[1,4],[0,0,3],[1,5]] return [3,4]
