## Solution explanation

The solution itself is quite self-explantory. However, there is a difference between `map()` function
in Python2 and Python3:

Before Python3, `map()` used to return a list, where each element of the result list was the result of the function 
applied on the corresponding element of the list or tuple. With Python 3, `map()` returns an iterator. Thus,
in order to get a list in Python3 after the map, we need to wrap map return with `list`.

## Reference

- https://www.python-course.eu/python3_lambda.php