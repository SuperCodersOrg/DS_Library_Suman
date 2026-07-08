# Daily Design Journal

**Project Title:** Building a Data Structures Library and Redis Lite
**Student Name:** Suman Mondal
**Date:** 07 July 2026

---

# Objective of the Day

The primary objective for today's work was to strengthen the design foundation of the Data Structures Library before starting the implementation phase. After discussing the initial Dynamic Array Design Proposal with my tutor, I planned to prepare a refined Version 2 by incorporating the suggested improvements and documenting the design in greater technical detail. Alongside this, I also intended to research the Linked List data structure, evaluate different implementation approaches, and prepare a complete design proposal that would serve as the implementation blueprint. The goal was to ensure that both data structures had a well-defined architecture, clear implementation strategy, and properly documented design decisions before writing any production code.

---

# 1. Specific Bug / Design Challenge

Since today's work focused entirely on design and documentation, I did not encounter any compiler errors or runtime exceptions.

The first challenge was revising the Dynamic Array Design Proposal after receiving feedback from my tutor. While the first version documented the required APIs and overall structure, several sections lacked detailed technical reasoning. Important concepts such as exception handling, template programming, memory management, and implementation trade-offs required more comprehensive explanations. Rather than making superficial edits, I needed to rethink how the proposal communicated the design decisions behind the implementation.

Another significant challenge arose while researching the Linked List implementation. Initially, I assumed that allocating memory using `malloc()` would completely initialize a newly created node. During my research, I discovered that `malloc()` only allocates raw memory and does not invoke constructors. Since each node stores an object of the templated type `T`, simply allocating memory leaves the object uninitialized. I studied how the placement `new` operator constructs an object in previously allocated memory and learned that the corresponding destructor must later be invoked explicitly before releasing the allocated memory. Understanding this distinction between memory allocation and object construction gave me a much clearer understanding of C++ object lifetime and manual memory management.

---

# 2. Failed Attempt

While revising the Dynamic Array proposal, my initial approach was to improve grammar, formatting, and a few descriptions while keeping the overall document unchanged. However, after carefully reviewing the tutor's feedback, I realized that these modifications would not significantly improve the quality of the proposal because the document still lacked sufficient technical depth.

Instead of editing individual paragraphs, I decided to rewrite several sections entirely. The Public API documentation was expanded to explain not only the purpose of each function but also its parameters, return type, internal behavior, and exception conditions. I documented the use of standard C++ exceptions, including `std::out_of_range` for invalid index access, `std::underflow_error` for deletion operations on an empty container, and `std::bad_alloc` for memory allocation failures. The Internal Representation section was enhanced with explanations of generic programming, Object-Oriented Programming principles, the Rule of Three, and memory organization. I also strengthened the Complexity Analysis and Design Decisions sections by adding technical reasoning behind implementation choices rather than simply listing them.

During the Linked List research, I initially explored implementing a Doubly Linked List because it simplifies backward traversal. After comparing it with a Singly Linked List in terms of memory overhead, implementation complexity, and the functional requirements of this project, I concluded that a Singly Linked List provides a simpler and more memory-efficient solution while still supporting all required operations. This comparison helped me justify the final implementation choice instead of selecting it based on familiarity alone.

---

# 3. Memory Diagram

The hand-drawn memory diagrams prepared during today's work have been submitted separately in accordance with the project handbook.

These diagrams helped me visualize the internal organization of both data structures and reinforced my understanding of how objects and dynamically allocated memory interact. While preparing the Linked List design, I also documented the sequence involved in node creation, beginning with raw memory allocation, followed by explicit object construction using placement `new`. This exercise clarified the difference between allocating memory and constructing an object, an important concept that will directly influence the implementation of the Linked List.

---

# 4. Code Reference

### Git Commits

* `docs(array): revise Dynamic Array design proposal (v2) with tutor feedback and improved technical documentation`
* `docs(linkedlist): add complete Linked List design proposal`

### Files Updated

* `docs/Design Proposal/ArrayDesignProposal.md`
* `docs/Design Proposal/LinkedListDesignProposal.md`
* `docs/Build Logs/build_logDay2Session2.md`
* `docs/Build Logs/build_logDay2Session3.md`

Today's work was limited to design documentation, technical research, architectural planning, and proposal refinement. No implementation source files were created or modified during this session.

---

# 5. Learning Reflection

Today's work reinforced the importance of investing sufficient time in the design phase before beginning implementation. Revising the Dynamic Array proposal showed me that a design document should explain not only what the implementation will do but also why each design decision has been made. Writing detailed explanations for exception handling, API behavior, memory management, complexity analysis, and implementation trade-offs required a deeper understanding of the data structure than simply describing its interface.

Researching the Linked List expanded my understanding of manual memory management in C++. One of the most valuable lessons was learning that memory allocation and object construction are independent operations. Understanding how placement `new` constructs objects in previously allocated memory, and why explicit destructor calls are required afterward, gave me a much stronger understanding of object lifetime management in C++.

By the end of the day, I had successfully completed a refined Version 2 of the Dynamic Array Design Proposal and a comprehensive Linked List Design Proposal. These documents now serve as detailed implementation blueprints and provide a clear architectural foundation for the upcoming development phase. Spending additional time on design today will help reduce implementation errors, simplify debugging, and make future enhancements easier to incorporate.
