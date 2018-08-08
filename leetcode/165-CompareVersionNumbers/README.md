## Solution explanation

### Python Solution

The solution itself is quite self-explantory. However, there is a difference between `map()` function
in Python2 and Python3:

Before Python3, `map()` used to return a list, where each element of the result list was the result of the function 
applied on the corresponding element of the list or tuple. With Python 3, `map()` returns an iterator. Thus,
in order to get a list in Python3 after the map, we need to wrap map return with `list`.

### C Solution

Write the code like us allowing us not explictly check the case when `version1 = "1"` and `version2 = "1.0.0"` case.
In addition, the reason we use `version1ReachEnd == 0` instead of `version1[i] != '\0'` is that after we do `i++` near
the end of the loop, the next iteration `version[i]` may lead to out-of-bound error.

## Reference

- https://www.python-course.eu/python3_lambda.php