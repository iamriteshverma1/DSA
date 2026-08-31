# Linked List

## Overview

A **Linked List** is a linear data structure where elements (nodes) are stored in a non-contiguous memory location. Each node contains data and a reference (link) to the next node, forming a chain.

## Key Characteristics

- **Dynamic Size**: Unlike arrays, linked lists can grow and shrink dynamically
- **Non-Contiguous Memory**: Nodes are scattered in memory, connected via pointers
- **No Random Access**: Must traverse from the beginning to access elements
- **Efficient Insertion/Deletion**: O(1) when position is known, O(n) for search

## Types of Linked Lists

### 1. Singly Linked List
- Each node points to the next node
- Traversal is unidirectional (head to tail)
- Memory efficient but limited traversal

```
Head → [Data|Next] → [Data|Next] → [Data|Null]
```

### 2. Doubly Linked List
- Each node has pointers to both next and previous nodes
- Bidirectional traversal
- Uses more memory but provides flexibility

```
Null ← [Prev|Data|Next] ↔ [Prev|Data|Next] ↔ [Prev|Data|Next] → Null
```

### 3. Circular Linked List
- Last node points back to the first node
- No null terminator
- Useful for circular buffer implementations

```
[Data|Next] → [Data|Next] → [Data|Next] ↻ (back to first)
```

## Node Structure

```
Node:
├── Data (value to store)
└── Next (pointer to next node)
```

## Common Operations

| Operation | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| Access | O(n) | O(1) |
| Search | O(n) | O(1) |
| Insertion | O(1)* | O(1) |
| Deletion | O(1)* | O(1) |
| Traverse | O(n) | O(1) |

*When position is known

## Basic Operations Implementation

### Insertion
1. **At Beginning**: O(1)
2. **At Middle**: O(n) for search + O(1) for insertion
3. **At End**: O(n) traversal + O(1) for insertion

### Deletion
1. **From Beginning**: O(1)
2. **From Middle/End**: O(n) traversal + O(1) deletion

### Traversal
- Visit each node once: O(n)
- Can be forward or backward (in doubly linked lists)

## Advantages

✓ Dynamic memory allocation
✓ Efficient insertion/deletion once position is found
✓ No memory wastage
✓ Flexible size adjustment

## Disadvantages

✗ No random access (must start from head)
✗ Extra memory needed for pointers
✗ Cache unfriendly (non-contiguous memory)
✗ Search requires linear traversal

## Applications

- **Implementation**: Stack, Queue, Hash tables, Graphs
- **Browser History**: Back/Forward navigation
- **Undo/Redo**: Reversible operations
- **File System**: Directory structures
- **LRU Cache**: Least Recently Used cache
- **Polynomial Representation**: Sparse polynomials

## Common Problems

1. Reverse a Linked List
2. Detect Cycle in Linked List
3. Find Middle of Linked List
4. Merge Sorted Linked Lists
5. Remove Nth Node from End
6. Flatten a Multilevel Linked List
7. Intersection of Two Linked Lists
8. Palindrome Linked List
9. Sort Linked List
10. Remove Duplicates

## Comparison with Arrays

| Feature | Linked List | Array |
|---------|------------|-------|
| Access Time | O(n) | O(1) |
| Insertion | O(1)* | O(n) |
| Deletion | O(1)* | O(n) |
| Memory | Scattered | Contiguous |
| Size | Dynamic | Fixed** |

*Position known | **Can be dynamic (ArrayList)

## Getting Started

This directory contains implementations and solutions for linked list problems in various languages:

- **Singly Linked List operations**
- **Doubly Linked List operations**
- **Circular Linked List operations**
- **Problem solutions and examples**

Explore the files in this directory to learn and practice linked list concepts!

## Resources

- Study the implementation files
- Try solving the common problems
- Understand time and space complexity
- Practice different variations and edge cases

---

Happy Learning! 🚀
