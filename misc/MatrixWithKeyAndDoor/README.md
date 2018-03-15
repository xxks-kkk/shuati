## Problem Description

Suppose you have a 2-D grid. Each point is either land or water. There is also a start point and a goal.
There are now keys that open up doors. Each key corresponds to one door.

Implement a function that returns the shortest path from the start to the 
goal using land tiles, keys and open doors.

Data Representation

The map will be passed as an array of strings. 
A map can have the following tiles.

```
0 = Water
1 = Land
2 = Start
3 = Goal

uppercase = door
lowercase = key
```

Example Maps (keys at each step are not required)

- No doors

```
MAP_1 = 
[‘02111’,
 ‘01001’,
 ‘01003’,
 ‘01001’,
 ‘01111’]
```

- Solution

```
(0, 1) with keys ‘’
(0, 2) with keys ‘’
(0, 3) with keys ‘’
(0, 4) with keys ‘’
(1, 4) with keys ‘’
(2, 4) with keys ''
```

- One door

```
MAP_2 = 
[‘02a11’,
 ‘0100A’,
 ‘01003’,
 ‘01001’,
 ‘01111’]
```

- Solution

```
Keys needed: a
(0, 1) with keys ‘’
(0, 2) with keys ‘’
(0, 3) with keys ‘a’
(0, 4) with keys ‘a’
(1, 4) with keys ‘a’
(2, 4) with keys ‘a’
```

## Solution explanation

BFS

## Reference

- https://stackoverflow.com/questions/39431473/how-to-find-the-shortest-path-in-a-puzzle-with-keys-and-doors
- https://instant.1point3acres.com/thread/306011
- https://ideone.com/CWwNwE
- http://community.bittiger.io/topic/123/pocket-gems-phone-interview