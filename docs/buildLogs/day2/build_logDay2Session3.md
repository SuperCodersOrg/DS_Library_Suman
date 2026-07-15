# Build Log – Session 3

**Project:** Building a Data Structures Library and Redis Lite
**Module:** Linked List
**Date:** 07-07-2026
**Duration:** 2 Hours

## Session Objective

The primary goal of this session was to understand the design of a Linked List data structure and prepare a detailed design proposal before starting its implementation. Instead of directly writing code, the focus was on researching different implementation approaches, selecting the most suitable design, and documenting every major decision to serve as a blueprint for development.

---

## Work Completed

### Research and Analysis

The session started with studying the fundamentals of the Linked List data structure. I reviewed how linked lists are organized in memory, how nodes are connected through pointers, and how dynamic memory allocation differs from contiguous memory allocation used in arrays.

I also analyzed the time complexity of common linked list operations such as insertion, deletion, searching, and traversal to understand where a linked list performs efficiently and where its limitations exist.

---

### Exploring Different Design Approaches

Before deciding on the implementation, multiple design alternatives were explored.

Some of the alternatives considered included:

* Singly Linked List vs. Doubly Linked List
* Generic implementation using templates vs. separate implementations for different data types
* Maintaining a size variable vs. calculating the size through traversal
* Returning references vs. returning copies from accessor functions
* Exception handling vs. returning error values
* Dynamic node allocation vs. fixed-size storage

Each approach was evaluated based on memory usage, simplicity, maintainability, and performance.

After comparing these alternatives, the Singly Linked List design was selected because it provides a simpler implementation while using less memory and fully satisfies the requirements of this project.

---

### Designing the Public API

Once the overall design was finalized, the public interface of the `LinkedList` class was planned.

The API includes all major operations required for a generic linked list, including:

* Constructors and destructor
* Copy constructor
* Copy assignment operator
* Insertion functions
* Deletion functions
* Element access
* Searching
* Traversal
* Size retrieval

For every public function, its purpose, parameters, return type, possible exceptions, and expected time complexity were documented before implementation.

---

### Designing the Internal Structure

The next step was to define how the linked list would be represented internally.

The internal design includes:

* A separate `Node<T>` class for storing data and the pointer to the next node.
* A `LinkedList<T>` class responsible for managing the entire list.
* Dynamic memory allocation for every node.
* A `head` pointer to access the first node.
* A `size` variable to maintain the number of elements.

A memory layout diagram was also prepared to visualize how the linked list object and dynamically allocated nodes are organized during execution.

---

### Documenting Complexity Analysis

A complete complexity analysis was prepared for every public member function.

For each operation, the following were documented:

* Best-case time complexity
* Average-case time complexity
* Worst-case time complexity
* Reason behind the complexity

This provides a clear understanding of the efficiency of each operation before implementation begins.

---

### Documenting Design Decisions

One of the major tasks of this session was preparing a dedicated **Design Decisions** section.

Instead of only describing the chosen implementation, each important design choice was justified by comparing it with alternative approaches.

The documented decisions include:

* Using C++ templates for generic programming.
* Keeping `Node` and `LinkedList` as separate classes.
* Choosing a Singly Linked List instead of a Doubly Linked List.
* Allocating nodes dynamically.
* Not maintaining capacity like a dynamic array.
* Maintaining a separate `size` variable.
* Returning references from the `get()` function.
* Using standard C++ exceptions for error handling.
* Implementing deep copy semantics using the Rule of Three.
* Reusing existing member functions to avoid duplicate code.

These decisions explain why the selected design is appropriate for the current project.

---

## Deliverables

By the end of this session, the following work was completed:

* Researched the Linked List data structure and its implementation techniques.
* Evaluated multiple design alternatives.
* Finalized the overall architecture of the Linked List.
* Designed the complete Public API.
* Documented the internal structure with a memory layout diagram.
* Prepared the complexity analysis for all public operations.
* Documented the key design decisions with proper justification.
* Completed the Linked List Design Proposal, which will serve as the reference document for the implementation phase.

---

## Outcome

This session was primarily focused on planning and design rather than coding. By the end of the day, a complete design proposal for the Linked List module had been prepared after researching different implementation strategies and evaluating multiple design choices. Having this documentation in place provides a clear roadmap for the implementation phase and helps ensure that the code developed in the next sessions follows a well-structured and maintainable design.
