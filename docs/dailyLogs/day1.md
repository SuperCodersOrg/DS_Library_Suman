# Daily Log Journal

**Project Title:** Building a Data Structures Library and Redis Lite  
**Student Name:** Suman Mondal  
**Date:** 06 July 2026  

---

# Objective of the Day

Today's objective was to complete the design phase of the Dynamic Array before starting the implementation. The focus was on defining the public interface, understanding the internal memory representation, analysing the time complexity of each operation, and documenting the major design decisions that will guide the implementation.

---

# Work Completed

## 1. Public API Design

I began by identifying the essential operations that a Dynamic Array should support. For each operation, I documented its purpose, parameters, return type, and expected behaviour.

The APIs finalized today include:

- `push_back(T ele)`
- `pop_back()`
- `insertAtIndex(int index, T ele)`
- `deleteAtIndex(int index)`
- `get(int index)`
- `isEmpty()`
- `isFull()`
- `getSize()`

This helped establish a clear interface before moving to implementation.

---

## 2. Internal Representation

After finalizing the API, I designed the internal structure of the Dynamic Array.

The class will maintain three data members:

- `T* arr`
- `int size`
- `int capacity`

I studied how these members are stored in memory and calculated the memory occupied by the object itself on a 64-bit system. I also prepared memory layout diagrams to visualize the relationship between the Dynamic Array object and the dynamically allocated memory block.

In addition, I documented why the class should follow the **Rule of Three** to ensure proper management of dynamically allocated memory.

---

## 3. Complexity Analysis

I analysed the time complexity of every public operation.

For each function, I documented:

- Best-case complexity
- Average-case complexity
- Worst-case complexity

Special attention was given to the `push_back()` operation. I studied the resizing process and analysed why repeated insertions have **O(1) amortized** time complexity despite occasional resizing operations.

---

## 4. Design Decisions

Finally, I documented the important implementation decisions that will be followed throughout the project.

These include:

- Initializing `capacity` with `1`
- Using contiguous memory allocation
- Implementing the class as a template
- Applying encapsulation
- Following the Rule of Three
- Using exception handling for invalid operations
- Adopting the capacity-doubling strategy for automatic resizing

These decisions provide a clear roadmap for the implementation phase.

---

# Challenges Faced

While analysing the Dynamic Array, I initially found it difficult to understand why `push_back()` is considered an **O(1) amortized** operation even though resizing requires copying all existing elements. After studying the capacity doubling strategy and the geometric series formed during resizing, I understood how the resizing cost is distributed across multiple insertions.

Another challenge was deciding the initial value of `capacity`. I considered initializing it to `0`, but after analysing the resizing logic, I concluded that starting with a capacity of `1` is necessary to allow successful memory allocation during the first insertion.

---

# Key Learning

Today's work improved my understanding of several important concepts:

- Designing a clear public interface before implementation.
- Internal memory representation of a Dynamic Array.
- Difference between stack memory and heap memory.
- Importance of contiguous memory allocation.
- Rule of Three for resource management.
- Amortized analysis of Dynamic Arrays.
- Trade-off between runtime performance and memory utilization during resizing.

---

# Summary of Progress

Today's work resulted in the successful completion of the design phase of the Dynamic Array. The complete Public API, Internal Representation, Complexity Analysis, and Design Decisions have been documented. This provides a solid foundation for beginning the implementation without requiring major design changes later.

---
