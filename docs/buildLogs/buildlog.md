

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