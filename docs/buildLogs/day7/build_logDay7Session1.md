# Build Log – Session 1

**Module:** DynamicArray Unit Testing and Build Environment Stabilization
**Date:** 14-07-2026
**Duration:** 3 Hours

## Goal

* Develop a comprehensive unit testing framework for the `DynamicArray` implementation using the Google Test framework.
* Verify the correctness of every public member function under normal, boundary, and exceptional conditions.
* Validate template compatibility using primitive types, standard library types, and user-defined objects.
* Establish a stable build and testing workflow using WSL, GCC, CMake, and Google Test.

---

## Problem Encountered

After completing the implementation of `DynamicArray`, I wanted to verify the correctness of every member function before using it as a dependency for higher-level data structures. Manual testing using a simple driver program was insufficient because it covered only a limited number of scenarios and made regression testing difficult after implementation changes.

At the same time, I was experiencing persistent issues with my Windows development environment. Although the compiler was correctly installed, Visual Studio Code frequently failed to detect or execute the correct compiler due to conflicting compiler installations and cached configuration files. These issues interrupted the testing workflow and prevented reliable project compilation.

To eliminate these problems, I decided to migrate the project to the Ubuntu environment provided by Windows Subsystem for Linux (WSL). This provided a clean Linux-based development environment with a consistent GCC toolchain and significantly improved build reliability.

Another challenge involved organizing the unit tests. Initially, I considered writing all test cases inside a single source file. However, as the number of scenarios increased, the file became difficult to maintain. To improve readability and modularity, I reorganized the test suite by creating separate test files for every public member function.

During testing, several compilation and build issues were encountered. Missing standard library headers caused compilation failures, while incorrect source file names inside `CMakeLists.txt` prevented CMake from generating the test executable successfully. These issues were identified and corrected before continuing with the implementation of additional test cases.

---

## What I Tried

### Development Environment

* Investigated existing MinGW and MSYS2 compiler installations.
* Reviewed Visual Studio Code compiler settings and Code Runner configuration.
* Verified compiler availability using GCC and G++ commands.
* Examined environment variables for conflicting compiler paths.
* Decided to migrate the project to Ubuntu using Windows Subsystem for Linux (WSL).
* Configured Visual Studio Code to work directly with the WSL environment.
* Verified installation of GCC, G++, CMake, Make, Git, and Google Test inside Ubuntu.
* Successfully configured and built the project using the Linux toolchain.

### Unit Testing

* Created separate Google Test source files for every public member function instead of using a single test file.
* Developed constructor test cases to verify the initial state of the container.
* Created comprehensive test cases for `push_back()`, including automatic resizing and large insertions.
* Tested `insertAtIndex()` for insertion at the beginning, middle, end, and invalid indices.
* Verified `pop_back()` under normal conditions and underflow scenarios.
* Implemented test cases for `deleteAtIndex()` covering different deletion positions and exception handling.
* Tested `get()` and both overloads of `operator[]` for valid and invalid access.
* Verified deep copy semantics using the copy constructor and copy assignment operator.
* Tested `getSize()`, `getCapacity()`, `isEmpty()`, and `isFull()` after various sequences of operations.
* Used Google Test's output capturing utilities to verify the `print()` function.
* Added test cases using `int`, `std::string`, and custom user-defined objects to validate template compatibility.
* Included exception testing using `EXPECT_THROW` for invalid indices and underflow conditions.

### Build and Debugging

* Rebuilt the project multiple times after adding new test files.
* Corrected missing standard library headers such as `<climits>`.
* Updated `CMakeLists.txt` after reorganizing test source files.
* Verified that every test file was compiled and linked correctly.
* Executed the complete Google Test suite after each major addition.
* Analysed failing test cases to distinguish between implementation bugs and incorrect test assumptions.
* Corrected the `isFull()` test after reviewing the internal capacity expansion strategy implemented by `push_back()`.
* Continued refining test cases until all DynamicArray unit tests passed successfully.

---

## Outcome

* Successfully migrated the project to a stable Ubuntu (WSL) development environment.
* Established a reliable CMake and Google Test build workflow for the project.
* Developed a comprehensive function-wise unit testing framework for the `DynamicArray` module.
* Verified the correctness of every public member function.
* Confirmed proper behaviour under normal, boundary, and exceptional conditions.
* Validated automatic capacity expansion and correct element shifting during insertion and deletion.
* Verified deep copy behaviour for both the copy constructor and copy assignment operator.
* Confirmed template compatibility using primitive types, strings, and user-defined objects.
* Resolved compilation, configuration, and testing issues encountered during development.
* Increased confidence in the correctness and stability of the `DynamicArray` implementation before proceeding to subsequent data structures in the library.

---

**Git Commit:** `81f012d` — Configured WSL-based development environment and implemented a comprehensive Google Test unit testing framework for DynamicArray.
