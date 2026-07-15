# Build Log – Session 1

**Module:** Redis Lite Design Proposal and System Architecture  
**Date:** 15-07-2026  
**Duration:** 2 Hours

## Goal

* Design the overall architecture of the Redis Lite application.
* Prepare a comprehensive Design Proposal following the documentation structure established for DynamicArray, LinkedList, and HashMap.
* Define the public interface, internal representation, complexity analysis, design decisions, and memory organization before beginning implementation.

---

## Problem Encountered

Unlike the previous modules, Redis Lite is an application rather than a standalone data structure. This required determining how responsibilities should be distributed between the application layer and the underlying `HashMap` implementation. A major challenge was deciding which operations should remain part of the command-processing engine and which should be delegated directly to the storage layer.

Another design consideration involved defining the execution flow of the application. Initially, the `run()` function was planned to execute from within the constructor. After evaluating object-oriented design principles, the execution model was revised so that object construction and program execution remain separate, with `run()` being invoked explicitly from `main()`.

The internal memory organization also required careful planning to accurately represent the relationship between `RedisLite`, `HashMap`, `DynamicArray`, `LinkedList`, and `HashNode` objects while maintaining consistency with the memory diagrams prepared for the previous modules.

---

## What I Tried

### Application Architecture

* Designed Redis Lite as an application layer built on top of the custom `HashMap`.
* Defined the responsibility of Redis Lite as command parsing, validation, execution, and output formatting.
* Kept all data storage operations delegated to the underlying `HashMap`, maintaining clear separation between the application layer and the storage engine.

### Public API Design

* Designed the complete class structure of the `RedisLite` class.
* Finalized the internal storage member:
  * `HashMap<string, string> store`
* Designed the public execution interface through the `run()` function.
* Identified the private helper functions responsible for implementing individual database commands:
  * `set()`
  * `get()`
  * `del()`
  * `exists()`
  * `count()`
  * `show()`
  * `clear()`
  * `toLower()`

### Command Processing Design

* Designed the complete command-processing workflow.
* Selected `getline()` for reading complete user commands.
* Chose `stringstream` for tokenizing command input into individual arguments.
* Designed case-insensitive command recognition by normalizing only the command keyword while preserving the original case of keys and values.
* Planned argument validation before invoking the corresponding database operation.

### Internal Representation

* Documented the interaction between Redis Lite and the custom `HashMap`.
* Mapped every supported command to its corresponding HashMap operation.
* Prepared the internal execution workflow illustrating command parsing, validation, execution, and formatted output generation.

### Memory Organization

* Designed the memory layout of the Redis Lite application.
* Illustrated the ownership relationship between:
  * `RedisLite`
  * `HashMap`
  * `DynamicArray`
  * `LinkedList`
  * `HashNode`
* Prepared the complete memory organization diagram showing stack and heap allocation.

### Complexity Analysis

* Documented the time complexity of every supported Redis Lite command.
* Derived command complexities from the corresponding `HashMap` operations.
* Identified constant-time operations (`SET`, `GET`, `DEL`, `EXISTS`, `COUNT`) and linear-time operations (`SHOW`, `CLEAR`).

### Design Decisions

* Documented the major architectural decisions taken during the design phase, including:
  * Interactive command-line interface
  * HashMap as the storage engine
  * String-based key-value storage
  * Case-insensitive command recognition
  * Separation of command processing and data storage
  * Dedicated member function for each command
  * Command parsing using `stringstream`
  * Tabular output formatting for the `SHOW` command
  * Object-oriented class design

### Documentation

* Completed the Redis Lite Design Proposal following the same documentation format used for the previous modules.
* Included:
  * Introduction
  * Public API
  * Internal Representation
  * Complexity Estimates
  * Design Decisions
* Added the Redis Lite memory organization diagram to the documentation.

### Project Setup

* Created the initial implementation source file:
  * `src/redisLite.cpp`
* Prepared the project structure for the upcoming implementation phase.

---

## Outcome

* Successfully completed the architectural design of the Redis Lite application.
* Finalized the public interface, internal representation, command-processing workflow, execution model, complexity analysis, and major design decisions.
* Designed and documented the memory organization of Redis Lite and its interaction with the underlying data structures.
* Established a complete design foundation that will guide the implementation of the Redis Lite command-line engine in subsequent development sessions.

---

**Git Commit:** `a78e3e5` — Added RedisLite Design Proposal.