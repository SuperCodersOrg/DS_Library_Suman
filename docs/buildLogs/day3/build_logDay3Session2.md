### Build Log – Session 2

**Project:** Building a Data Structures Library and Redis Lite  
**Module:** HashMap Design Proposal Development  
**Date:** 08-07-2026  
**Duration:** 2 Hours

---

## Objective

The objective of this session was to transform the architectural research completed in the previous session into a formal **HashMap Design Proposal**. The focus was on documenting the complete design, defining the public interface, describing the internal representation, analyzing algorithmic complexity, and recording the rationale behind every major design decision before beginning implementation.

---

## Work Done

### Preparing the Overall Design Proposal

The session began by organizing the design proposal into logical sections that describe the HashMap from both an implementation and documentation perspective.

The proposal was structured into:

- Public API
- Internal Representation
- Complexity Estimates
- Design Decisions

This structure ensures that both the implementation details and the reasoning behind them are clearly documented.

---

### Designing the Public Interface

The public interface of the HashMap was finalized by identifying every operation required by users of the data structure.

The following member functions were designed and documented:

- `insert()`
- `remove()`
- `get()`
- `exists()`
- `getSize()`
- `getLoadFactor()`
- `clear()`

For every function, the proposal documented:

- Purpose
- Parameters
- Return value
- Exception conditions
- Time complexity
- Internal workflow

This helped define clear responsibilities for each operation before implementation.

---

### Documenting the Internal Representation

The complete internal organization of the HashMap was formalized.

The proposal documented:

- Bucket array implementation using the custom DynamicArray.
- Storage of bucket pointers instead of LinkedList objects.
- Node structure containing key-value pairs.
- Memory ownership of buckets.
- Lazy allocation of linked lists.
- Collision handling using Separate Chaining.

Memory layout diagrams were also prepared to visualize how objects are distributed between stack and heap memory.

---

### Designing the Hashing Strategy

The hashing mechanism was refined further.

The proposal documented:

- Bucket index calculation using the modulo operation.
- Primitive type hashing.
- Polynomial Rolling Hash for strings.
- Future support for user-defined classes through customizable hash generation.

The remaining challenge of generic hashing for user-defined types was analyzed, and multiple extensible approaches were documented for future implementation.

---

### Complexity Analysis

Every public operation was analyzed to estimate its computational complexity.

Best-case, average-case, and worst-case complexities were documented along with explanations of how collision chains and rehashing affect runtime performance.

Special attention was given to explaining why insertion maintains amortized **O(1)** complexity despite occasional rehashing.

---

### Finalizing Major Design Decisions

The majority of the session was spent evaluating implementation alternatives before selecting the final design.

The documented decisions included:

- Generic implementation using templates.
- Representing each entry through `Node<K, V>`.
- DynamicArray as the bucket table.
- Storing pointers to LinkedList objects.
- Separate Chaining for collision resolution.
- Singly LinkedList for bucket management.
- Dedicated HashFunction class.
- Polynomial Rolling Hash for string keys.
- Initial capacity of **16**.
- Initial size of **0**.
- Initial load factor of **0.0**.
- Load factor threshold of **0.7**.
- Capacity doubling strategy during rehashing.
- Modular design through reusable helper functions.

For every decision, alternative approaches were evaluated and documented along with the reasons for selecting the final implementation.

---

### Refining Documentation

The proposal was reviewed and refined to improve technical accuracy and consistency.

Several sections were rewritten to provide clearer explanations of memory management, bucket allocation, collision handling, template usage, and object ownership. Diagrams, examples, and implementation notes were incorporated to make the proposal easier to understand and directly usable during the implementation phase.

---

## Outcome

By the end of this session, a comprehensive HashMap Design Proposal had been completed. The document captures the complete architecture, public interface, internal representation, complexity analysis, memory organization, and major design decisions. This proposal now serves as the implementation blueprint for the HashMap and provides a well-defined reference for subsequent development sessions.