### Build Log – Session 2

**Module:** Linked List Implementation
**Date:** 10-07-2026
**Duration:** 2 Hours

**Goal:**

* Implement insertion and deletion operations at both ends of the LinkedList.
* Ensure correct memory allocation and deallocation while maintaining the integrity of the list.
* Verify that the newly implemented operations work correctly with the previously implemented Rule of Three.

**Problem Encountered:**

* The primary challenge was correctly handling edge cases such as an empty list, a single-node list, and updates to the `head` pointer after insertion and deletion.
* Memory management had to be handled carefully to ensure that nodes were constructed, destroyed, and deallocated without causing memory leaks or dangling pointers.
* The `size` member also needed to remain consistent after every modification to the list.

**What I Tried:**

* Implemented `push_front()` to insert a new node at the beginning of the list by updating the `head` pointer.
* Implemented `push_back()` by traversing the list to the last node and appending a newly allocated node while correctly handling the empty-list case.
* Implemented `pop_front()` to remove the first node, update the `head` pointer, explicitly destroy the stored object, and free the allocated node memory.
* Implemented `pop_back()` by locating the second-last node, unlinking the last node, destroying the stored object, and releasing the allocated memory. Separate logic was added for single-node and empty-list scenarios.
* Updated the `size` variable appropriately after every insertion and deletion operation.
* Performed incremental compilation and testing after implementing each operation to verify correctness before proceeding to the next one.

**Outcome:**

* Successfully completed insertion and deletion operations at both ends of the LinkedList.
* All four fundamental operations (`push_front`, `push_back`, `pop_front`, and `pop_back`) correctly handle normal as well as boundary cases, including empty and single-node lists.
* Memory allocation and deallocation logic remained consistent with the Rule of Three implementation completed in the previous session.
* The LinkedList implementation is now prepared for the next phase, which includes indexed insertion, indexed deletion, searching, and element access operations.

**Git Commit:** `0d599f1` — *Implemented push and pop operations at both ends of the LinkedList and documented the previous development session in the build logs.*
