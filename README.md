# Tree Library

This is a generic `Tree` class implemented in C++ with various traversal iterators and graphical visualization using SFML.

## Features

- Supports a generic type `T` for node data.
- Maximum number of children per node is configurable (default is 2).
- Provides iterators for different tree traversal methods:
  - Pre-order
  - Post-order
  - In-order
  - Breadth-first search (BFS)
  - Depth-first search (DFS)
  - Heap-based traversal
  - Graphical visualization of the tree using SFML.

## Iterators
### Pre-order Iterator
Iterates over the tree in pre-order (root, left, right).

### Post-order Iterator
Iterates over the tree in post-order (left, right, root).

### In-order Iterator
Iterates over the tree in in-order (left, root, right).

### BFS Iterator
Iterates over the tree in breadth-first search order.

### DFS Iterator
Iterates over the tree in depth-first search order.

### Heap Iterator
Iterates over the tree based on a heap structure.