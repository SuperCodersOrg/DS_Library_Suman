# Build Log – Session 2

**Module:** LinkedList Core Operations and Rule of Three Unit Testing  
**Date:** 14-07-2026  
**Duration:** 2 Hours

## Goal

* Develop a comprehensive Google Test suite for the fundamental operations of the `LinkedList` implementation.
* Verify the correctness of the Rule of Three implementation, including the destructor, copy constructor, and copy assignment operator.
* Validate list construction, insertion operations, size management, and head pointer maintenance.
* Establish a consistent testing methodology matching the previously developed `DynamicArray` test suite.

---

## Problem Encountered

After completing the `DynamicArray` test suite, the next objective was to validate the `LinkedList` implementation before integrating it into higher-level data structures such as `HashMap`. Unlike `DynamicArray`, the linked list relies on manual memory management using `malloc()`, placement `new`, explicit destructor invocation, and `free()`. This required considerably more rigorous testing to ensure that node creation, destruction, and copying behaved correctly.

Initially, several issues arose while configuring the LinkedList testing environment. Duplicate executable targets inside `CMakeLists.txt` caused CMake configuration failures, while incorrect target definitions prevented Google Test from linking successfully. These configuration errors had to be resolved before the test suite could be executed.

Testing the destructor introduced another challenge. The original test cases assumed that the destructor counter would increase only when the linked list itself was destroyed. However, because temporary objects passed to `push_back()` and `push_front()` are destroyed immediately after insertion, the destructor count was larger than expected. After analysing object lifetimes, the test cases were redesigned to measure only the destructor calls performed during actual list destruction.

---

## What I Tried

### Google Test Configuration

* Created a dedicated Google Test executable for the `LinkedList` module.
* Added individual test source files for every public member function.
* Updated `CMakeLists.txt` to register all LinkedList test files.
* Corrected duplicate executable definitions and invalid target configurations.
* Rebuilt the project repeatedly to verify successful compilation after each modification.

### Constructor and Rule of Three Testing

* Developed constructor test cases to verify the initial state of an empty list.
* Verified correct initialization of the head pointer and list size.
* Implemented destructor test cases using a custom destructor tracking class.
* Analysed destructor behaviour caused by temporary object destruction.
* Redesigned destructor tests to accurately reflect object lifetime semantics.
* Verified deep copy behaviour using the copy constructor.
* Tested copy assignment for empty lists, populated lists, previous data replacement, and self-assignment.

### Core Operations

* Developed comprehensive test cases for `push_front()` covering insertion into empty and populated lists.
* Implemented extensive test cases for `push_back()` with sequential insertions and large datasets.
* Verified correct maintenance of list order after multiple insertions.
* Tested `getSize()` after various insertion sequences.
* Verified correct head pointer updates using `getHead()` following different operations.

### Template Validation

* Executed every major test using:
  * Primitive integer types
  * `std::string`
  * User-defined objects implementing copy construction and equality operators

---

## Outcome

* Successfully configured a dedicated Google Test framework for the `LinkedList` module.
* Resolved CMake configuration and target linking issues.
* Correctly validated constructor behaviour and initial list state.
* Verified proper implementation of the Rule of Three.
* Confirmed correct deep copy semantics for both copy constructor and copy assignment operator.
* Verified insertion operations at the front and back of the list.
* Confirmed accurate size tracking and head pointer updates after modifications.
* Established a modular and maintainable testing structure consistent with the `DynamicArray` test suite.

---

**Git Commit:** `9c29fd0` — Implemented Google Test framework for LinkedList constructors, Rule of Three, insertion operations, and utility functions.