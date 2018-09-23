## Solution explanation

最简单的方法+位运算的方法+board内存里放不下的情况／board很大只能存在disk里怎么办，
解决方法是从file里每次读三行，算中间一行的下一轮状态，第一行和最后一行例外
（中间那一行只用上下两行就能知道下个状态，然后扔掉最上面那行，在一行一行的load 然后处理） +input 是一百万乘以一百万版

## Reference

- https://leetcode.com/problems/game-of-life/discuss/73223/Easiest-JAVA-solution-with-explanation