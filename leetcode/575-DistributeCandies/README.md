## Solution explanation

The solution is no hard to understand. There are couple of things to note for
the implementation:

- `HashSet` is different from `HashMap` in the sense that: a `HashMap` is 
an implementation of [Map](http://docs.oracle.com/javase/6/docs/api/java/util/Map.html). 
A Map maps keys to values. The key look up occurs using the hash.
On the other hand, a `HashSet` is an implementation of [Set](http://docs.oracle.com/javase/6/docs/api/java/util/Set.html). 
A Set is designed to match the mathematical model of a set. 
A HashSet does use a HashMap to back its implementation. However, it implements an entirely different interface.
That's why `add` method in HashSet is described as "It is used to adds the specified element to this set if it is not already present."

- `for (int candy: candies) kinds.add(candy);` is something new in Java for me.

## Links to resources

- [Java tutorial](http://docs.oracle.com/javase/tutorial/collections/index.html)
- [Java HashSet tutorialpoint](https://www.javatpoint.com/java-hashset)
