# Build Log

**Project Title:** Building a Data Structures Library and Redis Lite  
**Student Name:** Suman Mondal
**Date:** 06 July 2026 
---

# Session 1

**Duration:** 2 Hours

### Goal

Prepare the design proposal for the Dynamic Array implementation before writing any production code.

The objectives for this session were:

- Design the public API of the Dynamic Array.
- Decide the internal data members required.
- Define the responsibilities of each public function.
- Decide the initial values of `size` and `capacity`.
- Study how a Dynamic Array manages memory internally.

---

### Problem Encountered

Initially, I focused only on the list of operations (`push_back`, `pop_back`, `insert`, etc.) without considering how the object itself would be represented in memory.

While designing the API, I realized that every operation depends on three internal variables:

- Pointer to the dynamically allocated array
- Current size
- Current capacity

Without clearly defining these data members first, it became difficult to explain how insertion, deletion, and resizing would actually work.

Another challenge was deciding whether the initial capacity should be `0` or `1`.

If both `size` and `capacity` started at `0`, then doubling the capacity during the first insertion would still result in `0`, preventing any memory allocation.

---

### What I Tried

To solve these issues, I first analyzed the internal memory representation of a Dynamic Array.

I decided to store three data members inside the class:

- `T* arr`
- `int size`
- `int capacity`

I also calculated the memory occupied by the object itself on a 64-bit system:

- Pointer = 8 bytes
- `size` = 4 bytes
- `capacity` = 4 bytes

Total object size = **16 bytes** (excluding dynamically allocated heap memory).

Next, I prepared a hand-drawn memory layout diagram showing:

- the Dynamic Array object on the stack,
- the contiguous array allocated on the heap,
- the relationship between the pointer and heap memory,
- the values of `size` and `capacity`.

After understanding the memory layout, I finalized the responsibilities of every public API function.

---

### Outcome

At the end of the session, I completed the overall API design and the Internal Representation section of the design proposal.

Major decisions finalized:

- Dynamic Array will be implemented as a template class.
- The object stores only three data members.
- Initial `size` = 0.
- Initial `capacity` = 1.
- Heap memory is managed through a pointer.
- Public interface and internal representation are now clearly separated.

The memory layout diagram also gave me a much better understanding of how the object and heap memory interact during execution.

---

