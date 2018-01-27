## Solution explanation

### Solution 1: built-in reverse operation [Accepted]

The first solution relies on the built-in reverse operation provided by python. The implementation is
straightforward, which is coded in `reverseWords`.

### Solution 2: two pointers

The idea of the solution is that we first reverse the whole string and then we reverse each word. Finally,
we clean up all the leading spaces and the multiple spaces between words. Several implementation notice
here:

For the following code chunk: 

```
while(i < j || (i < n && s[i] == ' ')) i++; 
while(j < i || (j < n && s[j] != ' ')) j++;
```

The execution order is following:

- `i` and `j` both starts from `0`. `i` is the start pointer and `j` is the end pointer.

1. `while(i < j || i<n && s[i]==’ ‘) i++` is to skip the leading spaces before every word. Only
`i<n && s[i]==’ ‘` is evaluated to `True` this case. 
2. `while (j<i)` points `j` to the same position as `i`, because `i` has already skipped the 
leading spaces in prior while
3. `while(j<n && a[j]!=’ ')` find the whole word starts from `i`, ends at `j` until `a[j]` is `' '` or `j<n`
4. `while(i<j)` `i` is the start index of last word, `j-1` is the end index of the last word, points `i` to the same position as `j`, 
then start finding the next word

In other words, the above code chunk is abbreviation of the following code chunk:

```
while(i < n && s[i] == ' ') i++; 
while(j < i) j++;
while(j < n && s[j] != ' ') j++;
while(i < j) i++;
```

Another piece of code that needs to explain is in `cleanSpaces`:

```
while (j < n && s[j] == ' ') j++; // skip spaces
while (j < n && s[j] != ' ') s[i++] = s[j++]; // keep non spaces
if (j < n) s[i++] = ' ';
```

- `while (j < n && s[j] == ' ') j++;` skipps leading spaces and mutliple spaces between words and find
the first letter of the word
- `while (j < n && s[j] != ' ') s[i++] = s[j++];` starts to write the word to the position pointing by `i`,
which will override any leading or multiple spaces
- `if (j < n) s[i++] = ' '` inserts a space and sets the `i` to the position where the next word should start

The solution is implemented in `reverseWordsInAString.c`. However, due to unknown reason, the code
cannot pass OJ but the test case listed in the `main` should demonstrate the correctness of the code.

## Reference

- https://leetcode.com/problems/reverse-words-in-a-string/discuss/47720