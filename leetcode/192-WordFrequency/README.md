## Solution explanation

Let's work through the solution. 

- `cat words.txt | tr -s ' ' '\n'`. `tr -s` replace all the appearances of `' '` with `'\n'`.

```
the
day
is
sunny
the
the
the
sunny
is
is
```

- `cat words.txt | tr -s ' ' '\n' | sort`

```
day
is
is
is
sunny
sunny
the
the
the
the
```

- `cat words.txt | tr -s ' ' '\n' | sort | uniq -c`. `uniq -c` counts the number of occurence of each line
in the input 

    - `uniq` -- report or filter out repeated lines in a file
    - `-c` -- -c      Precede each output line with the count of the number of times the line occurred in the input, 
    followed by a single space.

```
   1 day
   3 is
   2 sunny
   4 the
```

- `cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -rn`

    - `-n, --numeric-sort` compare according to string numerical value
    - `-r, --reverse` reverse the result of comparisons

```
   4 the
   3 is
   2 sunny
   1 day
```

- `cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -rn | awk '{print $2,$1}'`

```
the 4
is 3
sunny 2
day 1
```

## Reference

- https://leetcode.com/problems/word-frequency/discuss/55443/My-simple-solution-(one-line-with-pipe) 