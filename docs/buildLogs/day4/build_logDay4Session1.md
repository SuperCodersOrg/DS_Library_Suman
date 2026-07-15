### Build Log – Session 1

**Module:** Dynamic Array & Linked List Implementation
**Date:** 09-07-2026
**Duration:** 2 Hours

**Goal:**

* Refine the existing DynamicArray implementation by addressing pending issues and improving code consistency.
* Begin the implementation of the LinkedList data structure.
* Establish the foundational LinkedList architecture with proper memory management using the Rule of Three.

**Problem Encountered:**

* The DynamicArray implementation required several refinements to improve consistency between the header and source files, simplify the implementation, and correctly handle edge cases.
* While starting the LinkedList implementation, the major challenge was designing ownership semantics for dynamically allocated nodes. A shallow copy would result in multiple objects sharing the same nodes, leading to memory leaks and double deletion. Therefore, a deep-copy strategy was necessary from the beginning.
* As the implementation evolved, the design proposal also needed to be updated to accurately reflect the latest API and design decisions.

**What I Tried:**

* Refactored the DynamicArray implementation by cleaning up constructors, the copy constructor, the copy assignment operator, and several member functions to improve readability and maintainability.
* Improved edge-case handling by redirecting deletion of the last element through `pop_back()`, simplifying validation logic, and keeping the header declarations synchronized with the implementation.
* Updated the LinkedList design proposal by refining the proposed API and renaming the Rule of Three section from **Copy Assignment Operator** to **Copy Assignment Operator Overloading** for better technical accuracy.
* Created `include/linkedList.h` and defined the `Node` structure along with declarations for all planned LinkedList operations.
* Created `src/linkedList.cpp` and implemented the initial Rule of Three components:

  * Default constructor
  * Destructor
  * Copy constructor
  * Copy assignment operator with self-assignment protection and deep-copy semantics
* Added `main.cpp` to support compilation and incremental testing during the development of the LinkedList module.

**Outcome:**

* Successfully completed the initial setup of the LinkedList module by creating its header and source files.
* Implemented the Rule of Three, establishing safe object lifetime management and deep-copy behavior for dynamically allocated nodes.
* Refined the DynamicArray implementation through code cleanup, consistency improvements, and better edge-case handling.
* Updated the LinkedList design proposal to keep the documentation synchronized with the implementation.
* **Git Commit:** `2dbc7a1` — *Started LinkedList implementation with header file and Rule of Three, refined DynamicArray implementation, and updated the LinkedList design proposal.*
