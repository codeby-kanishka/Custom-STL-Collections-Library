# Custom Template Library (CTL)
## Technical Design Proposal

---

## 1. Summary

Custom Template Library (CTL) is a C++ STL-inspired generic container framework designed to provide reusable and type-safe data structures.

The library implements custom:

- DynamicArray
- LinkedList
- HashMap

containers with manual memory management and optimized performance strategies.

---

## 2. Objectives

- Build reusable containers using C++ templates
- Implement efficient memory management
- Maintain optimized time complexity


---

## Template Design

Templates were used to make the data structures work with different data types. Without templates, the same code would need to be written separately for int, string, and other types, which would increase code duplication.

Example:

```cpp
DynamicArray<int> numbers;
DynamicArray<string> names;

LinkedList<double> values;

HashMap<string, int> data;
```

---


# DynamicArray<T>

## Overview

A DynamicArray is a linear data structure that stores elements in contiguous heap memory.

It automatically increases capacity at runtime when more storage is required.

---

# API Specification

## Constructors

| Method | Complexity | Reason |
|-|-|-|
| DynamicArray() | O(1) | Initializes variables and creates initial storage |
| DynamicArray(int capacity) | O(1) | Creates storage with given capacity |
| DynamicArray(int size,const T& value) | O(n) | Creates n initialized elements |
| Copy Constructor | O(n) | Performs deep copy |
| Destructor | O(n) | Destroys elements and releases memory |
| operator=() | O(n) | Copies another object safely |

---

## Methods

| Method | Average | Worst | Reason |
|-|-|-|-|
| append(value) | O(1) | O(n) | Usually adds the element at the end; worst case occurs when internal resizing is required. |
| insert(index,value) | O(n) | O(n) | Elements require shifting |
| remove(index) | O(n) | O(n) | Elements after the removed index are shifted. |
| get(index) | O(1) | O(1) | Direct index access |
| set(index,value) | O(1) | O(1) | Direct modification |
| size() | O(1) | O(1) | Stored variable returned |
| capacity() | O(1) | O(1) | Stored capacity returned |
| isEmpty() | O(1) | O(1) | Checks size |

---

# DynamicArray Design Decisions

## Heap Allocation

DynamicArray uses contiguous heap memory to provide flexible runtime storage.

---

## Initial Capacity

Initial capacity = **4**

Reasons:

- avoids unnecessary memory usage
- reduces resizing for small collections
- provides balanced starting memory allocation

---

## Resizing Strategy

Growth Factor:

```
newCapacity = oldCapacity * 1.5
```

Reasons:

- less memory wastage compared to doubling
- reduces frequent reallocations
- balances performance and memory usage

---

## Memory Management

Initially malloc() was used.

Problem:

- malloc only allocates raw memory
- constructors are not called
- fails for objects like string

Solution:

- Placement new constructs objects manually
- Destructor is manually called before freeing memory

Example:

```cpp
new(&arr[i]) T(value);

arr[i].~T();

free(arr);
```

---

# LinkedList<T>

## Overview

LinkedList stores elements as separate nodes connected through pointers.

It does not require contiguous memory.

---

# API Specification

## Constructors

| Method | Complexity | Reason |
|-|-|-|
| LinkedList() | O(1) | Creates empty list |
| Copy Constructor | O(n) | Creates deep copy |
| Destructor | O(n) | Deletes every node |
| operator=() | O(n) | Clears old and copies new data |

---

## Methods

| Method | Average | Worst | Reason |
|-|-|-|-|
| insertFront(value) | O(1) | O(1) | Updates head |
| insertBack(value) | O(1) | O(1) | Uses tail pointer |
| insertAt(index,value) | O(n) | O(n) | Traversal required |
| deleteFront() | O(1) | O(1) | Updates head |
| deleteAt(index) | O(n) | O(n) | Finds node first |
| search(value) | O(n) | O(n) | Sequential search |
| size() | O(1) | O(1) | Stored size |
| isEmpty() | O(1) | O(1) | Size check |
| print() | O(n) | O(n) | Traverses nodes |

---

# LinkedList Design Decisions

- Uses dynamic node allocation
- Implements singly linked list
- Reduces extra memory overhead
- Maintains head pointer
- Maintains tail pointer for O(1) insertion at end

---

## Node Structure

Node is created as a struct because:

- it only stores data
- contains next pointer
- no major functionality required

Example:

```cpp
struct Node
{
    T data;
    Node* next;
};
```

The Node remains private inside LinkedList to protect internal implementation.

---

# HashMap

## Overview

HashMap stores data in key-value pairs.

It provides efficient:

- insertion
- searching
- deletion

using hashing.

---

# API Specification

## Constructors

| Method | Complexity | Reason |
|-|-|-|
| HashMap() | O(1) | Initializes buckets |
| Copy Constructor | O(n) | Copies all pairs |
| Destructor | O(n) | Releases memory |
| operator=() | O(n) | Performs deep copy |

---

## Methods

| Method | Average | Worst | Reason |
|-|-|-|-|
| set(key,value) | O(1) | O(n) | Collision chains possible |
| get(key) | O(1) | O(n) | Searches bucket |
| exists(key) | O(1) | O(n) | Checks key presence |
| remove(key) | O(1) | O(n) | Removes from bucket |
| size() | O(1) | O(1) | Stored count |
| loadFactor() | O(1) | O(1) | Calculates usage |
| isEmpty() | O(1) | O(1) | checks for directy stored size variable

---

# Hash Function Design

Uses generic hash policy:

```cpp
HashMap<Key, Value, Hash>
```

Supports:

## Default Hash Function

A generic byte-based default hash function is implemented to support template keys. It converts the key's memory representation into bytes and combines them using a polynomial hash approach with prime multiplier 31. The final hash value is mapped to a bucket index using modulo operation. Specialized hash functions can be added for complex data types to improve hashing behavior.

### Primitive Types

Numeric value is converted into hash.

Example:

```cpp
index = hash(key) % capacity;
```

### String

Characters are processed to generate a numeric hash.



---

# Collision Handling

Technique Used:

## Separate Chaining

Reasons:

- handles high collisions efficiently
- avoids clustering
- provides stable node based storage

Structure:

```
Bucket Array

0 -> NULL

1 -> (key,value) -> (key,value)

2 -> NULL

3 -> (key,value)
```

---

# Load Factor

Maximum Load Factor:

```
0.75
```

Formula:

```
loadFactor = numberOfElements / bucketCount
```

Reasons:

- prevents long chains
- balances memory usage
- maintains efficient operations

When exceeded:

- bucket array grows
- all keys are rehashed

---

# HashMap Capacity

Initial Bucket Count:

```
8
```

Reasons:

- provides enough distribution
- reduces early collisions
- avoids excessive unused memory

During resizing:

```
newCapacity = oldCapacity * 2
```

---

# Rule Of Three Implementation

All containers implement:

- Destructor
- Copy Constructor
- Assignment Operator

Reasons:

- prevent shallow copy issues
- avoid memory leaks
- safely manage heap resources

---

# Conclusion

The Custom Template Library provides reusable STL-like generic containers implemented from scratch using C++ templates.

The project focuses on:

- manual memory management
- efficient algorithms
- optimized resizing strategies
- deep copying
- type independent design