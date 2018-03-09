## Problem Description

- Version 1:

输入是 一个String array. 比如说{"Albert II","Polo IV","Alw V","Elizabeth XXV", "Albert XL","Polo XLVI"} 
其中每个string 被一个空格隔开. 要求是输出String 数组。优先按前半部分 字母排序，如果前半部分的word 是一样的，
按后半部分的罗马数值由 __大到小__ 排。

Implemented in `royalNames1`

- Version 2:

一堆皇家名字，前半部分是名字，后半部分是罗马数字，例如Henry IV，要求先按照前半部分lexicographically排序，相同的按后半部分
__从小到大__ 排序

Implemented in `royalNames`

## Reference

- https://github.com/settyblue/HackerRank/blob/master/sortRoyalNames/src/Main.java