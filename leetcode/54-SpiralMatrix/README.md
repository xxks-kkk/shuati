## Solution Explanation

### Intuition

Draw the path that the spiral makes. We know that the path should turn clockwise whenever 
it would go out of bounds or into a cell that was previously visited.

### Algorithm

Let the array have $R$ rows and $C$ columns. $\text{seen[r][c]}$ denotes that the cell on the
$\text{r}$-th row and $\text{c}$-th column was previously visited. 
Our current position is $\text{(r, c)}$, facing direction $\text{di}$, 
and we want to visit $\text{R} x \text{C}$ total cells.

As we move through the matrix, our candidate next position is $\text{(cr, cc)}$. 
If the candidate is in the bounds of the matrix and unseen, then it becomes our next position; 
otherwise, our next position is the one after performing a clockwise turn.

### Implementation

To understand how we perform a clockwise turn, we use `dr` to denote the direction of the movement
row-wise and `dc` to denote the direction of the movement column-wise.

```python
dr = [0, 1, 0, -1]
dc = [1, 0, -1, 0]
```

In `dr`, `1` means moving downward, `0` means staying at the current row, and `-1` means moving upward.
In `dc`, `1` means moving to the right, `0` means staying at the current column, and `-1` means 
moving to the left. `di = (di + 1) % 4` means looping between direction offsets.

- Time Complexity: $O(N)$, where $N$ is the total number of elements in the input matrix. 
We add every element in the matrix to our final answer.

- Space Complexity: $O(N)$, the information stored in `seen` and in `ans`. 


## Reference

- https://leetcode.com/problems/spiral-matrix/solution/