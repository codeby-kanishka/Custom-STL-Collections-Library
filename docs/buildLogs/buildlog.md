

## Date: June 23, 2026
**Duration:** 45 minutes

### Goal:
Set up initial repository structure and documentation files for Custom STL Collections Library.

### Problem Encountered:
The project repository needed a clean organization before continuing implementation, and basic documentation was missing.

### What I Tried:
- Created the required folder structure for organizing source code, tests and documentation.
- Added README.md file with initial placeholder content.
- Verified repository changes.
- Committed the updated project structure to GitHub.

### Outcome:
Successfully prepared a clean project workspace and initialized documentation setup for future development.


---
## Session 2
---

## Date: June 23, 2026
**Duration:** 90 minutes

### Goal:
Improve DynamicArray memory allocation approach.

### Problem Encountered:
Needed to replace normal dynamic allocation using new with manual memory management using malloc() while keeping the container generic. 
The allocation approach worked for primitive types, but handling objects like strings required proper object initialization.

### What I Tried:
- Studied the difference between new and malloc.
- Understood how memory allocation works internally.
- Analyzed memory handling for primitive and user-defined data types.
- Explored placement new for creating objects in manually allocated memory.
- Modified allocation approach for template based DynamicArray.
- Reviewed object creation and cleanup during resizing.

### Outcome:
Improved understanding of manual memory handling and finalized the allocation strategy for DynamicArray using malloc along with placement new for object construction.

---

## Session - 3
---

## Date: June 23, 2026
**Duration:** 120 minutes

### Goal:
Implement DynamicArray with support for different data types.

### Problem Encountered:
Initial memory allocation approach worked for primitive data types, but handling objects like strings caused issues because proper object initialization was required.

### What I Tried:
- Implemented template based DynamicArray structure.
- Studied the issue with storing string and object types.
- Updated allocation logic using malloc with placement new.
- Added constructors for array initialization.
- Implemented append, insert, remove, get and set operations.
- Added resizing logic for increasing capacity dynamically.
- Handled object cleanup during memory release.

### Outcome:
Successfully implemented DynamicArray with manual memory management that supports primitive types as well as objects like strings.

## Session 5 


---

## Date: June 23, 2026
**Duration:** 45 minutes

### Goal:
Add exception handling support for DynamicArray memory operations.

### Problem Encountered:
Since DynamicArray manages memory manually, allocation failures or errors during object creation needed to be handled safely to avoid memory issues.

### What I Tried:
- Added checks for memory allocation failure cases.
- Implemented exception handling during DynamicArray resizing.
- Added cleanup logic to release already allocated memory if an error occurs.
- Tested memory handling behavior during allocation and copying operations.

### Outcome:
Improved DynamicArray reliability by handling memory related failures and ensuring safer resource management.



## Session 6

---
## Date: June 24, 2026
**Duration:** 60 minutes

### Goal:
Implement the basic structure of a generic Singly Linked List container.

### Problem Encountered:
Needed to design a node-based data structure that supports different data types while maintaining dynamic memory allocation manually.

### What I Tried:
- Implemented template-based Singly Linked List class.
- Created Node structure containing data and next pointer.
- Added head pointer to maintain the starting node of the list.
- Implemented basic node creation and linking logic.
- Added initial insertion and traversal functionality.
- Managed dynamic node allocation and cleanup.

### Outcome:
Successfully created the basic structure of a generic Singly Linked List with template support, node-based memory layout and manual memory management.

---

## Date: June 24, 2026
**Duration:** 30 minutes

### Goal:
Optimize insertion operations in Singly LinkedList.

### Problem Encountered:
While implementing copy constructor and insertion logic, adding elements at the end required traversing the entire linked list every time, making end insertion take O(n) time.

### What I Tried:
- Analyzed the insertion process in Singly LinkedList.
- Added an insertBack function for adding nodes at the end.
- Introduced a tail pointer to maintain direct access to the last node.
- Updated insertion and copying logic to use the tail pointer.
- Handled tail updates during insertion and deletion operations.

### Outcome:
Improved end insertion performance from O(n) to O(1) by maintaining a tail pointer, while keeping proper memory management and LinkedList functionality.