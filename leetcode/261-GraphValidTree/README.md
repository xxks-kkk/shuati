## Solution explanation

We need to check the following:

- whether graph contains cycle
- whether graph is connected

To check cycle:

- Create a disjoint sets for each vertex of the graph
- For every edge $u$,$v$ in the graph
    - Find root of the sets to which $u$ and $v$ belongs
    - If $u$ and $v$ have the same root in disjoint sets => find cycle
    
To check connected, we don't need to do the following before `return true`:

```cpp
for(int i = 0; i < n; ++i)
{
  if (id[i] == i && size[i] == n)
  {
    return true;
  }
}
return false;
```

Because once we check $|E| = |V|-1$ and there is no cycle, we are guaranteed that the graph is connected.

## Reference

- http://www.cs.yale.edu/homes/aspnes/pinewiki/GraphTheory.html
- http://www.techiedelight.com/union-find-algorithm-cycle-detection-graph/ 
- https://leetcode.com/problems/graph-valid-tree/discuss/69019/Simple-and-clean-c++-solution-with-detailed-explanation.