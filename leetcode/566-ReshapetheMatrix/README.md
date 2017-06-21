Several things to highlight:

- If the requested shape is invalid, we can't just return `nums` 
(which is very tempting to do). Think about what the judge is probably doing. 
Probably it uses and frees all the result data 
(the data pointed to by the return value as well as what we 
write in `returnSize` and `columnSizes`). 
So we should create an independent copy of the input matrix with all its own data. 
In other words, we need to create a return matrix no matter what situation we 
are in (whether the requested shape is valid or not) and we just need to
fill in the right dimensions depend on the scenario

```c
  int returnColSize, i;
  if (r*c != numsRowSize * numsColSize)
  {
    *returnSize = numsRowSize;
    returnColSize = numsColSize;

  }
  else
  {
    *returnSize = r;
    returnColSize = c;
  }
```

- `columnSizes` are passed in with the type `int**`. This is recurring theme of
modifying an array within a function. 

```c
  *columnSizes = malloc(sizeof(int) * (*returnSize));
  for(i = 0; i < *returnSize; i++)
  {
    result[i] = malloc(sizeof(int) * returnColSize);
    (*columnSizes)[i] = returnColSize;
  }
```

Please take a look at [my post on this matter](http://zhu45.org/posts/2017/Jan/08/modify-array-inside-function-in-c/)
on how exactly this is done.

- How we actually reshape the matrix is worth memorizing.

```c
  for(i = 0; i < numsRowSize*numsColSize; i++)
  {
    result[i/returnColSize][i%returnColSize] = nums[i/numsColSize][i%numsColSize];
  }
```
