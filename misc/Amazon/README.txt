# Problems

## LC20. Valid Parentheses

- https://raw.githubusercontent.com/xxks-kkk/shuati/master/leetcode/20-ValidParentheses/validParentheses.cc

## LC438. Find All Anagrams in a String

- https://raw.githubusercontent.com/xxks-kkk/shuati/master/leetcode/438-FindAllAnagramsInAString/findAllAnagramsInAString.cc

## Find the min steps of maze

意思是说有一个M*N的maze，0代表可以通过，1代表不可以通过，然后给你一个出口（x,y），找从（0,0）到出口的最少steps，如果找不到path就返回-1

Similar to LC63. Unique Path II; Same question as LC505 (?): Ball cannot stop rolling (i.e., change direction) until hit the wall but this assumption probably not true in the actual problem.

- https://raw.githubusercontent.com/xxks-kkk/shuati/master/leetcode/63-UniquePathsII/uniquePathsII.py
- https://raw.githubusercontent.com/xxks-kkk/shuati/master/leetcode/505-TheMazeII/theMazeII.cc

## LC 675. Cut off Tree for Golf Event

golf球场修场地。
public int flatFields (int numRows, int numColumns, List<List<Integer>> fields) {}
让小明帮公司球场修场地，给一个二维的链表fields，场地里有坑，不能走。 场地里有树要砍掉。最后目的返回是修好一层的场地的最小步数。
Ex1:
[
[1, 3, 0, 2]
[1, 1, 3, 1]
]
上图中的1代表平地，可以走。 0代表坑，不能走。 大于1的数字代表树木，需要砍掉。规则是从上下左右四个角开始任选一个开始走，先砍数字小的树木。 比如2 < 3，那么就得先走2。
上图如果从右下角开始走依次经过的坐标是： （1， 3） -> (0, 3) -> (1, 3) -> (1, 2) -> (1, 1) -> (1, 0) 所以返回的最小步数是5， 因为通过这个路径可以修平第二层的球场[1, 1, 3, 1]， 并‍‌‌‍‌‌‍‍‍‌‌‌‍‌‌‌‌且走到左下角终点。
Ex2:
[
[1, 0]
[3, 2]
]
上图中的最小步数返回-1因为，没有办法修好一层， 因为从左上角1开始走，不能走到0， 也不能走3， 因为在全局中3比2大，必须先走2。所以就没法走了。

- https://raw.githubusercontent.com/xxks-kkk/shuati/master/leetcode/675-CutOffTreesforGolfEvent/cutOffTreesforGolfEvent.cc

## 买水果 （水果题）

public static int checkWinner (List<List<String>> codeList, List<String> shoppingCart) {}
说的是小明要帮公司买水果，给了一个codeList， 里面装的是他买的水果，给了一个shoppingCart里面装的是target水果，目标是检查codelist里的水果顺序是否和shoppingCart里的顺序匹配。
注意的是只有codelist中的所有链表的item之后加起来小于等于shoppingcart里item之和才可能返回1。 另外在codelist中有可能出现item时 "anything"， 它可以和任意的水果匹配。
Ex1:
codelist:
[
[apple, apple],
[orange, banana, orange]
]
shoppingCart: [orange, apple, apple, orange, banana, orange]
return 1, 因为codelist里的顺序和shoppingcart里除了第一个orange之后的水果顺序匹配

Ex2:
codelist:
[
[orange, banana, orange]，
[apple, apple]
]
shoppingCart: [orange, apple, apple, orange, banana, orange]
return 0, 因为codeList里的顺序和shoppingcart没法匹配。

Ex3:
codelist:
[
[apple, apple],
[orange, banana, orange],
[pear, orange, grape]
]
shoppingCart: [orange, apple, apple, orange, banana, orange, pear, grape]
return 0, 因为codelist里最后一个[pear, orange, grape]中的orange没法和shoppingcart里的水果匹配。

Ex4:
codeList:
[ [apple, apple], [orange, anything, orange] ]
shoppingCart:
[orange, apple, apple, orange, mango, orange]
return 1

Ex5:
codelist:
[
[apple, apple],
[orange, banana, orange]
]
shoppingCart: [orange, apple, apple, orange, apple, orange, banana, orange]
return 1, 虽然[apple, apple] 和 [orange, banana, orange] 中间插入了[orange, apple]

- "Anything" 是和单一水果匹配

## Score Gathering

score gathering, 输入一个unsorted integer array,  给这个array 打分，基本就是建BST, 然后 BFS 输出

4, 2, 5, 5, 6, 1, 4

[num] :［出现次数］

变成
        4:2
  2:1       5:2
1:1            6:1

输出 4:2,2:1,5:2,1:1，，，6:1

- https://github.com/xxks-kkk/shuati/blob/a68f66519e6abfa563515cae35bc54fe7c559a0b/misc/Amazon/scoreGathering.cc

## construct BST 后找俩node之间distance

Given a list of unique integers, construct the binary tree by given order without rebalancing,
then find out the distance between two nodes.

public static int bstDistance(int[] values, int n, int node1, int node2)

for example:

values= [5,6,3,1,2,4], n is the size of values, node1 is 2, node2 is 4, then function return 3
构建完BST如下，2和4呢，距离就是3
      5
   3      6
1     4
  2

- Similar to LC863 in terms of how to solve it (https://www.cnblogs.com/grandyang/p/10686922.html)

# Reference

- https://www.1point3acres.com/bbs/thread-225078-1-1.html
- https://www.1point3acres.com/bbs/thread-288738-1-1.html
- https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=289918&highlight=amazon%2Boa
- https://www.1point3acres.com/bbs/thread-192414-1-1.html
