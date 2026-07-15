# Build Log – Session 2

**Module:** Hash Function Design and Generic Key Support  
**Date:** 13-07-2026  
**Duration:** 2 Hours  

## Goal

- Improve the hashing mechanism to support a wider range of key types.
- Explore how the `HashMap` should behave when user-defined data types are used as keys.
- Ensure the implementation remains generic while preventing incorrect usage wherever possible.

---

## Problem Encountered

After completing the basic `HashMap` implementation, I realized that the existing `HashFunction` class only handled primitive data types and `std::string`. As soon as I considered user-defined objects as keys, several design questions arose.

The first challenge was deciding how a generic `generateHash()` function should compute a hash value for an unknown type. Initially, I explored hashing based on the object's memory address, but that would generate different hash values for two different objects containing identical data, making it unsuitable for a HashMap.

I then investigated reading the raw bytes of an object using `reinterpret_cast` and computing a polynomial-style hash over those bytes. While this approach could work for simple types, I learned that it is not reliable for all user-defined classes because objects may contain padding bytes or pointer members whose values do not represent the logical state of the object.

Another issue I encountered was consistency between hashing and key comparison. Since the HashMap compares keys using `operator==` inside methods such as `insert()`, `exists()`, and `get()`, any user-defined key type must provide equality comparison. Without it, these operations cannot function correctly.

---

## What I Tried

- Added overloaded `generateHash()` implementations for primitive data types and `std::string`.
- Experimented with a generic template version of `generateHash()` for user-defined types.
- Explored hashing by reading an object's raw bytes and combining them using a polynomial hash with multiplier `31`.
- Investigated compile-time validation to ensure that key types satisfy the requirements needed by the HashMap.
- Decided to enforce support for `operator==` using `static_assert`, since equality comparison is required throughout the HashMap implementation.
- Considered allowing user-defined classes to provide their own `hashCode()` function, while keeping the raw-byte hashing implementation as a fallback for generic types.

---

## Outcome

- Extended the design of the `HashFunction` module to support both built-in and generic key types.
- Established a clear strategy for handling user-defined keys through compile-time constraints and customizable hashing.
- Improved the overall design of the HashMap by ensuring that hashing and equality comparison remain consistent for every supported key type.
- The HashMap is now better prepared to support user-defined objects while maintaining type safety and generic programming principles.

---

**Git Commit:** `ace72f2` — *Implementing all the methods of HashMap and do changes in DynamicArray & LinkedList methods due to implementation requirement of hashmap*