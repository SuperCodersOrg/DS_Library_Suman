# Build Log – Session 1

**Module:** HashMap Implementation  
**Date:** 13-07-2026  
**Duration:** 2 Hours  

## Goal

- Complete the remaining member functions of the `HashMap` class.
- Integrate all basic operations required for a functional hash table, including searching, retrieval, deletion, and bucket traversal.
- Make the implementation reusable by relying on the previously implemented `DynamicArray`, `LinkedList`, and `HashFunction` modules.

---

## Problem Encountered

After completing the insertion logic, I needed to implement the remaining operations of the `HashMap`. Since every operation depends on computing the hash value and locating the correct bucket, I first spent time understanding the complete execution flow before writing the implementation.

One challenge was deciding how `insert()` should behave when the same key is inserted multiple times. Instead of allowing duplicate keys, I wanted the existing value to be updated. This required careful coordination between `insert()`, `exists()`, and `get()`.

While implementing these methods, I also realized that the existing `DynamicArray` and `LinkedList` interfaces required a few modifications so they could be reused efficiently by the `HashMap` implementation.

---

## What I Tried

- Implemented `exists()` by generating the hash value, computing the bucket index, and traversing the corresponding linked list to compare keys.
- Implemented `get()` using the same traversal logic and returned a reference to the stored value, throwing an exception if the key was not found.
- Implemented `remove()` by first checking whether the key exists, locating the corresponding bucket, creating a temporary `HashNode`, and delegating the deletion to the linked list.
- Updated `insert()` so that it first calls `exists()`. If the key is already present, the stored value is updated using `get()` instead of inserting a duplicate node.
- Implemented `printBuckets()` to traverse every bucket and display its complete chaining structure for debugging and verification.
- Modified a few methods in the `DynamicArray` and `LinkedList` modules wherever necessary so that the HashMap implementation could integrate with them cleanly.

---

## Outcome

- Successfully completed the remaining core operations of the `HashMap` class.
- The HashMap now supports insertion with value updates, key lookup, retrieval, deletion, bucket traversal, and exception handling for missing keys.
- The implementation reuses the existing `DynamicArray`, `LinkedList`, and `HashFunction` modules, reducing duplicate logic and keeping the code modular.
- The completed functionality provides a stable foundation for the next phase of improving hashing support for different key types.

---

**Git Commit:** `ace72f2` — *Implementing all the methods of HashMap and do changes in DynamicArray & LinkedList methods due to implementation requirement of hashmap*