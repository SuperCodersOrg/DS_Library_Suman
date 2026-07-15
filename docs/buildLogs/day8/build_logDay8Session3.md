# Build Log – Session 3

**Module:** HashMap Unit Testing and Redis Lite Testing  
**Date:** 15-07-2026  
**Duration:** 2 Hours

## Goal

* Develop a comprehensive Google Test suite for every public member function of the generic `HashMap` implementation.
* Verify the correctness of the implementation under normal, boundary, exceptional, and generic template scenarios.
* Validate the behavior of Redis Lite by testing its command-line interface through automated CLI interaction.
* Ensure both the generic data structure library and the Redis Lite application behave correctly under realistic usage.

---

## Problem Encountered

After completing the implementation of the generic `HashMap`, the next objective was verifying its correctness through extensive unit testing. Since `HashMap` is a fully templated container, designing reusable test cases that validate both primitive and user-defined data types introduced additional complexity.

Another challenge involved validating copy semantics, duplicate-key handling, load factor computation, bucket indexing, rehashing, and exception handling while avoiding unnecessary redundancy across test files.

During testing, several build issues also surfaced. Including `hashFunction.cpp` inside the header resulted in multiple definition linker errors because every translation unit generated its own copy of the non-template member functions. Resolving this required separating template and non-template implementations correctly and linking `hashFunction.cpp` through CMake.

Testing Redis Lite presented another challenge because almost all functionality is encapsulated inside the interactive `run()` loop and private helper functions. Rather than exposing internal methods solely for testing, the application needed to be validated by simulating complete command-line sessions through redirected input and captured console output.

---

## What I Tried

### HashMap Unit Testing

* Created independent Google Test files for every public member function:
  * Constructor
  * Destructor
  * Copy Constructor
  * Copy Assignment Operator
  * `getbucketIndex()`
  * `rehash()`
  * `insert()`
  * `remove()`
  * `get()`
  * `exists()`
  * `getSize()`
  * `getLoadFactor()`
  * `printBuckets()`
  * `clear()`

* Organized each function into its own dedicated test file to maintain readability and modularity.

### Generic Template Validation

* Designed test cases using multiple template instantiations.
* Verified functionality with:
  * Integer keys and values.
  * String keys and integer values.
  * Integer keys and string values.
* Added user-defined key types implementing:
  * `operator==`
  * `hashCode()`
* Verified that the generic implementation behaves consistently regardless of key or value type.

### Duplicate Key Handling

* Added dedicated tests to verify insertion of duplicate primitive keys.
* Added similar tests for user-defined key objects representing the same logical key.
* Confirmed that:
  * Existing values are updated.
  * Duplicate entries are not created.
  * Map size remains unchanged after updating an existing key.

### Rehash Validation

* Inserted sufficient elements to exceed the configured load factor threshold.
* Verified that:
  * Automatic rehashing occurs.
  * All previously inserted key-value pairs remain accessible.
  * Element count remains unchanged after resizing.

### Exception Testing

* Verified exceptions for invalid operations including:
  * Retrieving a non-existent key.
  * Removing a non-existent key.
* Confirmed correct behavior after clearing the map.

### Hash Function Verification

* Validated hashing behavior indirectly through `HashMap` operations.
* Confirmed successful insertion, retrieval, lookup, and duplicate detection using:
  * Primitive keys.
  * String keys.
  * User-defined objects providing `hashCode()`.
* Ensured identical logical keys produce consistent lookup behavior.

### Redis Lite CLI Testing

* Created automated CLI tests by redirecting:
  * Standard input.
  * Standard output.
* Simulated complete Redis Lite sessions using command sequences.
* Tested commands including:
  * `SET`
  * `GET`
  * `DEL`
  * `EXISTS`
  * `COUNT`
  * `SHOW`
  * `CLEAR`
  * `HELP`
  * `EXIT`
* Verified command parsing, validation, success messages, error messages, and database state transitions without exposing private member functions.

### Build System Improvements

* Fixed linker issues caused by including `hashFunction.cpp` within header files.
* Separated template and non-template implementations appropriately.
* Updated CMake configuration to compile and link `hashFunction.cpp` only once.
* Integrated `HashMapTesting` and `RedisLiteTesting` executables into the project's Google Test configuration.

### Test Suite Refinement

* Reduced redundant test cases while maintaining broad coverage.
* Ensured each test validates a unique behavior rather than repeating existing scenarios.
* Focused on correctness, boundary conditions, template compatibility, exception safety, and practical usage.

---

## Outcome

* Successfully completed a comprehensive unit testing suite for the generic `HashMap`.
* Verified every public interface through modular Google Test files.
* Confirmed correct behavior for primitive, string, and user-defined template types.
* Validated duplicate-key updates, automatic rehashing, exception handling, copy semantics, and load factor management.
* Developed automated Redis Lite CLI tests by simulating complete user interaction rather than testing internal implementation details.
* Improved the project build configuration by resolving template and linker issues involving the hash function implementation.
* Established a maintainable and scalable testing framework covering both the reusable data structure library and the Redis Lite application, providing confidence in the correctness of the overall system.

---

**Git Commit:** `9d68b52` — Completed HashMap Unit Testing and Redis Lite Testing.