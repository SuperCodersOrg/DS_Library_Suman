### Build Log – Session 3

**Module:** Linked List Implementation
**Date:** 10-07-2026
**Duration:** 2 Hours

**Goal:**

* Complete the remaining functionality of the `LinkedList` class by implementing indexed insertion, indexed deletion, searching, indexed element access, traversal, and size retrieval.
* Reuse previously implemented operations wherever possible to keep the implementation modular and avoid redundant code.

**Problem Encountered:**

* Implementing indexed insertion and deletion required careful traversal to the correct node while preventing invalid pointer dereferencing.
* Boundary cases such as inserting at the beginning/end of the list and deleting the first/last node required different handling from middle-node operations.
* Since the LinkedList is implemented as a template, traversal and element access needed to remain generic without making assumptions about the stored data type.
* It was also important to ensure that every structural modification correctly updated the `size` member and preserved the integrity of the linked list.

**What I Tried:**

* Implemented `insertAtIndex()` by first validating the supplied index. For boundary cases, the function delegates to the existing `push_front()` and `push_back()` implementations, while middle insertions traverse to the preceding node before linking the newly allocated node into the list.
* Implemented `deleteAtIndex()` with appropriate validation and reused `pop_front()` and `pop_back()` for boundary cases. For middle-node deletion, the target node is unlinked, its contained object is explicitly destroyed, and the allocated memory is released.
* Implemented `search()` using linear traversal to locate the first occurrence of an element and return its index, returning `-1` when the element is not present.
* Implemented `get()` by validating the requested index, traversing only to the required node, and returning a `const` reference to avoid unnecessary copying of objects.
* Implemented `traverse()` to sequentially visit every node and print each element using the stream insertion operator, allowing the function to work with any user-defined type that overloads `operator<<`.
* Implemented `getSize()` to provide constant-time retrieval of the current number of elements stored in the list.
* Verified that every insertion and deletion operation consistently updated the `size` member and maintained correct node links.

**Outcome:**

* Successfully completed the implementation of all planned LinkedList member functions.
* The LinkedList now supports insertion and deletion at arbitrary indices, linear search, indexed element access, traversal, and constant-time size retrieval.
* Boundary conditions are handled through reuse of previously implemented push and pop operations, reducing code duplication and improving maintainability.
* The implementation remains fully generic through templates and forms a complete, reusable LinkedList module that is ready for comprehensive testing and future integration into the Collections Library.

**Git Commit:** `d635228` — *Implemented the remaining LinkedList member functions: `insertAtIndex`, `deleteAtIndex`, `search`, `get`, `getSize`, and `traverse`.*
