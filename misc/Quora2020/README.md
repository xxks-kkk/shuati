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


## matrix

v1: 输入为n*n数字矩阵，要求其中数字按照出现频率升序排列，相同频率按照大小升序排列。比如 1 0 3 2 2 3  0 0 0，排序后为1 2 2 3 3 0 0 0 0。 返回一个n*n矩阵，矩阵中的数字为排序后数字按照平行反对角线方向从右下到左上依次填充。说的很难理解，看个例子：假设排序后数字为1 2 3 4 5 6 7 8 9，返回
9 7 4
8 5 2
6 3 1
