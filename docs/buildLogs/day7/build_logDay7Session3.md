# Build Log – Session 3

**Module:** LinkedList Element Manipulation, Search Operations, and Output Validation  
**Date:** 14-07-2026  
**Duration:** 2 Hours

## Goal

* Complete the Google Test suite for all remaining `LinkedList` member functions.
* Verify insertion, deletion, searching, element access, removal, and traversal operations under normal, boundary, and exceptional conditions.
* Validate template compatibility and ensure the integrity of the linked list after consecutive modifications.

---

## Problem Encountered

Once the Rule of Three and insertion operations were fully tested, the remaining member functions required significantly broader coverage because each operation could modify node links in different ways. In particular, insertion and deletion operations needed to be validated at the beginning, middle, and end of the list while ensuring that list integrity remained intact after every modification.

Another challenge involved testing the `traverse()` function, since it writes directly to `std::cout` instead of returning data. To automate verification, Google Test's output capturing utilities were incorporated so that printed output could be compared against the expected sequence of elements.

Several test files initially failed to compile because helper classes used for template testing had not been included consistently across all source files. This issue was resolved by standardising the helper object definition throughout the LinkedList test suite.

---

## What I Tried

### Insertion and Deletion Operations

* Developed comprehensive test cases for `insertAtIndex()` covering insertion at the beginning, middle, end, and invalid indices.
* Verified correct node linkage after consecutive insertions.
* Implemented `deleteAtIndex()` test cases for deleting the first, middle, and last nodes.
* Tested deletion until the list became empty.
* Verified exception handling for invalid indices and underflow conditions.

### Removal and Search

* Developed extensive test cases for `remove()` using value-based deletion.
* Verified removal of head, middle, tail, and duplicate elements.
* Tested removal of non-existent elements.
* Implemented `search()` test cases covering successful searches, unsuccessful searches, duplicate values, and empty list behaviour.

### Element Access

* Developed test cases for `get()` covering valid indices, invalid indices, and empty list access.
* Verified correct retrieval of first, middle, and last elements.
* Confirmed that repeated access operations did not modify the list.

### Traversal

* Implemented output verification using Google Test's standard output capture mechanism.
* Verified traversal of:
  * Empty lists
  * Single-node lists
  * Multi-node lists
  * Lists containing duplicate values
  * String lists
  * User-defined object lists
* Confirmed that traversal preserved list integrity.

### Template Validation

* Repeated testing with:
  * Integer values
  * `std::string`
  * Custom user-defined objects
* Added large dataset tests to verify algorithm correctness under heavier workloads.

### Build and Debugging

* Added every new LinkedList test file to `CMakeLists.txt`.
* Rebuilt the project after implementing each group of test cases.
* Corrected compilation errors caused by duplicate helper class definitions.
* Resolved missing declarations by standardising the helper class across all test files.
* Executed the complete LinkedList Google Test suite after every major update.
* Reviewed failed test cases to distinguish implementation issues from incorrect testing assumptions.
* Refined test cases until all LinkedList unit tests executed successfully.

---

## Outcome

* Successfully completed comprehensive testing of every remaining `LinkedList` member function.
* Verified correct behaviour for insertion, deletion, removal, searching, traversal, and element access.
* Confirmed proper exception handling for invalid operations.
* Validated template compatibility using primitive types, standard library types, and custom objects.
* Verified that list structure remained consistent after consecutive modifications.
* Completed a modular Google Test suite providing comprehensive coverage of the entire `LinkedList` implementation.

---

**Git Commit:** `9c29fd0` — Completed comprehensive Google Test coverage for LinkedList insertion, deletion, searching, traversal, and element access operations.