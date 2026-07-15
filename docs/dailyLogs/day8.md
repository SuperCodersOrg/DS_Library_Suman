# Daily Design Journal – Day 8

## Module – Redis Lite Design, Implementation, HashMap Unit Testing & Redis Lite CLI Testing

**Date:** 15-07-2026

---

## Section 1 — Specific Bug

### Challenges During the Development of Redis Lite and the HashMap Testing Framework

After completing the implementation of the generic `HashMap`, the next phase of the project involved building Redis Lite as an application layer on top of the custom data structure while simultaneously developing a comprehensive testing framework for the completed `HashMap`. Unlike previous modules, Redis Lite introduced application-level concerns such as command parsing, interactive execution, user input validation, and formatted output in addition to the underlying data structure operations.

The first challenge involved designing a clean architecture that clearly separated the responsibilities of Redis Lite and the `HashMap`. Rather than embedding storage logic inside the application, Redis Lite was designed to function solely as a command-processing layer responsible for parsing user commands, validating input, invoking the appropriate `HashMap` operation, and presenting results to the user.

Implementing the command-processing engine required designing an execution loop capable of continuously accepting user input, tokenizing commands, validating their syntax, dispatching the correct operation, and recovering gracefully from runtime exceptions. Since database operations such as retrieving or deleting non-existent keys throw exceptions from the underlying `HashMap`, centralized exception handling became necessary to prevent the application from terminating after invalid commands.

While preparing the HashMap testing framework, additional complexity arose because the implementation is completely generic. Every public member function needed to be validated using multiple template instantiations, including primitive types, strings, and user-defined objects implementing both `operator==` and `hashCode()`. Particular attention was given to duplicate-key insertion, deep copy semantics, automatic rehashing, exception handling, and load factor computation while avoiding redundant test cases.

Several build and linker issues were also encountered during testing. Including `hashFunction.cpp` inside the header caused multiple definition linker errors because non-template member functions were compiled separately in every translation unit. After restructuring the implementation, template and non-template functions were separated correctly, and `hashFunction.cpp` was linked only once through the CMake build configuration.

Testing Redis Lite presented another challenge because almost all application functionality is encapsulated inside the interactive `run()` function. Instead of exposing private helper functions solely for testing, the command-line interface was validated by redirecting standard input and output, allowing complete Redis Lite sessions to be executed automatically through Google Test.

---

## Section 2 — Failed Attempt

Initially, I planned to execute the Redis Lite application directly from its constructor. Although this simplified object creation, it tightly coupled object initialization with program execution and prevented controlled testing. After reviewing object-oriented design principles, the execution model was redesigned so that object construction and program execution remain separate, with `run()` being invoked explicitly from `main()`.

During the initial implementation of command parsing, I considered converting the entire input string to lowercase before processing. This approach simplified command recognition but unintentionally modified the case of keys and values stored inside the database. The implementation was revised so that command keywords are processed case-insensitively while preserving the original key and value data.

While testing the `HashMap`, the first collection of test cases contained unnecessary duplication across multiple files. Several scenarios validated identical behaviour using different data types without providing additional coverage. The testing framework was reorganized to eliminate redundant cases while retaining comprehensive validation of normal operation, boundary conditions, exception handling, template compatibility, and user-defined objects.

Another unsuccessful approach involved testing the internal helper functions of Redis Lite individually. Since these functions are intentionally private, exposing them solely for testing would have weakened encapsulation. Instead, the testing strategy was redesigned to validate the complete command-processing pipeline by simulating user interaction through redirected console input and captured output.

During compilation, including `hashFunction.cpp` from within the header produced multiple definition linker errors because every translation unit generated duplicate implementations of the non-template member functions. After separating template and non-template implementations and updating the CMake configuration to compile `hashFunction.cpp` only once, the build completed successfully.

Several test cases involving user-defined objects also failed initially because the helper classes did not fully satisfy the requirements imposed by the generic `HashMap`. Providing consistent implementations of `operator==` and `hashCode()` resolved these compilation issues and enabled proper validation of duplicate-key behaviour for custom object types.

---

## Section 3 — Memory Diagram

**Hand-drawn memory diagrams submitted separately.**

The diagrams include:

* Overall Redis Lite architecture showing the interaction between the application layer and the underlying `HashMap`.
* Internal memory organization illustrating the ownership relationship among `RedisLite`, `HashMap`, `DynamicArray`, `LinkedList`, and `HashNode`.
* Command-processing workflow from user input through tokenization, validation, execution, and formatted output.
* HashMap bucket organization before and after automatic rehashing.
* Duplicate-key insertion flow demonstrating value replacement without creating additional nodes.
* Google Test execution workflow for HashMap and Redis Lite CLI testing.

---

## Section 4 — Code Reference

### Git Commits

**Commit:** `a78e3e5`

* Completed the Redis Lite Design Proposal.
* Finalized application architecture, command-processing workflow, complexity analysis, memory organization, and design decisions.

**Commit:** `26f37f6`

* Implemented the Redis Lite command-line interface.
* Added command parsing, validation, exception handling, interactive execution, and HashMap integration.

**Commit:** `9d68b52`

* Completed the comprehensive Google Test framework for the `HashMap`.
* Implemented automated Redis Lite command-line testing.
* Resolved template and linker issues related to the hash function implementation.

### Implemented Features

#### Redis Lite Design

* Designed the complete Redis Lite architecture.
* Defined the public API and internal representation.
* Documented complexity analysis and design decisions.
* Prepared memory organization diagrams.

#### Redis Lite Implementation

* Implemented the interactive command-processing engine.
* Added support for:
  * `SET`
  * `GET`
  * `DEL`
  * `EXISTS`
  * `COUNT`
  * `SHOW`
  * `CLEAR`
  * `HELP`
  * `EXIT`
* Implemented case-insensitive command recognition.
* Added centralized exception handling.
* Integrated the custom `HashMap` as the storage engine.
* Added formatted output through `showAll()`.

#### HashMap Testing

* Developed dedicated Google Test files for every public member function.
* Verified constructor, destructor, Rule of Three, insertion, deletion, searching, lookup, load factor computation, bucket indexing, rehashing, clearing, and output functions.
* Tested duplicate-key handling for both primitive and user-defined objects.
* Validated template compatibility using integers, strings, and custom key types.
* Verified exception handling for invalid operations.

#### Redis Lite Testing

* Developed automated CLI-based Google Test cases.
* Simulated complete user sessions through redirected input and output streams.
* Verified command parsing, syntax validation, exception handling, and command execution without exposing private member functions.

### Files Modified

* `include/redisLite.h`
* `src/redisLite.cpp`
* `include/hashMap.h`
* `src/hashMap.cpp`
* `include/hashFunction.h`
* `src/hashFunction.cpp`
* `testing/HashMapTesting/*`
* `testing/RedisLiteTesting/*`
* `CMakeLists.txt`
* `docs/buildLogs/build_logDay8Session1.md`
* `docs/buildLogs/build_logDay8Session2.md`
* `docs/buildLogs/build_logDay8Session3.md`

### Relevant Functions

#### RedisLite

* `RedisLite()`
* `run()`
* `set()`
* `get()`
* `remove()`
* `exists()`
* `count()`
* `clear()`
* `show()`
* `toLower()`

#### HashMap

* `HashMap()`
* `~HashMap()`
* `HashMap(const HashMap&)`
* `operator=()`
* `getbucketIndex()`
* `rehash()`
* `insert()`
* `remove()`
* `exists()`
* `get()`
* `getSize()`
* `getLoadFactor()`
* `clear()`
* `printBuckets()`
* `showAll()`

#### HashFunction

* `generateHash(int)`
* `generateHash(char)`
* `generateHash(bool)`
* `generateHash(short)`
* `generateHash(long)`
* `generateHash(float)`
* `generateHash(double)`
* `generateHash(const std::string&)`
* `generateHash(const K&)`

---

## Section 5 — Learning Reflection

Today's work strengthened my understanding of both application-layer software design and generic data structure verification. Designing Redis Lite demonstrated how a well-structured application can remain independent of its storage engine by delegating all data management responsibilities to reusable components while focusing exclusively on command processing, validation, and user interaction.

Developing the comprehensive HashMap testing framework reinforced the importance of systematic software verification for generic template libraries. Rather than validating only primitive types, I learned how template-based containers must also be tested using strings and user-defined objects to ensure consistent behaviour across different instantiations. Testing duplicate-key updates, automatic rehashing, deep copy semantics, exception handling, and load factor computation significantly improved confidence in the correctness of the implementation.

Resolving linker issues related to template and non-template implementations also deepened my understanding of C++ compilation, translation units, and template instantiation. Separating template implementations from ordinary member functions and configuring CMake correctly provided a clearer understanding of how large C++ projects should be organized.

Finally, testing Redis Lite through automated command-line interaction instead of exposing private helper functions emphasized the importance of validating software through its public interface. By the end of the day, Redis Lite had evolved from a documented design into a fully functional command-line application backed by a thoroughly tested generic `HashMap`, establishing a reliable foundation for future enhancements to the DS Library project.