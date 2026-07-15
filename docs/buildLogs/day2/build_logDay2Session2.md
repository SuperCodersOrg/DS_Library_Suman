# Build Log – Session 2

**Project:** Building a Data Structures Library and Redis Lite
**Component:** Dynamic Array Design Proposal (Version 2)
**Date:** 07-07-2026
**Duration:** 1.5 hours

## Objective

After completing the first version of the Dynamic Array Design Proposal, I discussed it with my tutor to review the design, documentation quality, and technical explanations. Based on the feedback, I prepared a second version of the proposal by improving the overall structure, strengthening the technical content, and making the document more suitable as a professional software design proposal.

## Work Done

### Reviewing the Initial Proposal

I began this session by reviewing the first version of the proposal along with the feedback received from my tutor. While the initial draft covered the basic design of the Dynamic Array, many explanations were brief and several implementation decisions lacked proper justification. The focus of this session was not to change the design itself but to improve how the design was documented and explained.

### Improving the Overall Structure

The proposal was reorganized to make it easier to read and navigate. The introduction was rewritten to clearly explain the purpose of the Dynamic Array and provide an overview of the four major sections included in the proposal. The heading hierarchy and formatting were also made consistent throughout the document, resulting in a cleaner and more professional presentation.

### Refining the Public API Documentation

Each public member function was revised with more detailed explanations. Instead of only describing what a function performs, I documented its purpose, parameters, return type, internal working, and possible failure conditions.

I also included the reasoning behind several implementation choices. For example, I explained why the `get()` function returns `T&` instead of `T`, allowing direct access to the stored element while avoiding unnecessary copying. Similarly, I documented that `insertAtIndex()` internally calls `push_back()` when insertion occurs at the end of the array, and `deleteAtIndex()` reuses `pop_back()` when deleting the last element. Reusing these functions reduces duplicate code and improves maintainability.

### Improving Exception Handling

One of the major improvements in this revision was replacing generic error descriptions with appropriate standard C++ exceptions. Instead of simply mentioning that an error would occur, I clearly documented which exception should be thrown under different situations.

For invalid index access in functions such as `get()`, `insertAtIndex()`, and `deleteAtIndex()`, the proposal now specifies `std::out_of_range`. Deletion operations like `pop_back()` or `deleteAtIndex()` throw `std::underflow_error` when performed on an empty array, while memory allocation failures during resizing are handled using `std::bad_alloc`. Documenting these exception conditions makes the API behavior more predictable and aligns the implementation with standard C++ programming practices.

### Expanding the Internal Representation

The Internal Representation section was enhanced by adding several concepts that were missing from the first version. I included a detailed explanation of template programming to describe why `template<typename T>` is used and how it enables the same implementation to work with different data types without rewriting the class.

I also explained the Object-Oriented Programming principles used in the implementation, including encapsulation, abstraction, modularity, and code reuse. The Rule of Three section was rewritten with clearer reasoning, and the explanation of stack and heap memory organization was improved to provide a better understanding of how the Dynamic Array manages memory internally.

### Strengthening the Complexity Analysis

The complexity section was refined by simplifying the complexity table while improving the reasoning behind each time complexity. Additional explanation was added for amortized analysis, including why repeated `push_back()` operations remain efficient despite occasional resizing. The proposal also explains the capacity doubling strategy and the geometric series involved during memory reallocation, providing stronger justification for the amortized O(1) insertion complexity.

### Expanding the Design Decisions

The Design Decisions section received the largest number of improvements during this session. Several implementation choices that were only briefly mentioned in the first version were expanded with proper technical reasoning.

Additional explanations were added for the capacity doubling strategy, why shrinking is intentionally not performed during deletion, manual memory management using `malloc()`, placement `new`, explicit destructor calls, and the importance of the Rule of Three. I also documented the trade-offs between Dynamic Arrays and Linked Lists, explaining the situations in which each data structure is more suitable.

### Improving Technical Writing and Documentation

Apart from technical improvements, I carefully reviewed the entire proposal to improve its overall quality. Grammatical errors were corrected, technical terminology was made more precise, repetitive statements were removed, and several explanations were rewritten to improve clarity. The formatting of headings, code snippets, tables, and descriptions was also standardized to maintain consistency throughout the document.

## Outcome

By the end of this session, the second version of the Dynamic Array Design Proposal became significantly more detailed, technically accurate, and professionally structured than the initial draft. The proposal now not only describes the interface and implementation of the Dynamic Array but also explains the reasoning behind important design decisions, exception handling strategies, memory management techniques, and complexity analysis. This revised version provides a much stronger foundation for the implementation phase of the project.
