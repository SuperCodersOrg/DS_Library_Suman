### Build Log – Session 1

**Project:** Building a Data Structures Library and Redis Lite  
**Module:** HashMap Research and Architecture Design  
**Date:** 08-07-2026  
**Duration:** 2 Hours

---

## Objective

The objective of this session was to study the internal working of the **HashMap** data structure and design its overall architecture before implementation. Instead of directly writing code, the focus was placed on understanding how industrial hash-based containers organize data, resolve collisions, manage memory, and maintain efficient lookup performance. The knowledge gained during this session would serve as the foundation for preparing the HashMap Design Proposal and its subsequent implementation.

---

## Work Done

### Understanding HashMap Fundamentals

The session began by studying how a HashMap stores information as **key-value pairs** and performs insertion, retrieval, deletion, and update operations efficiently through hashing.

I explored the complete lookup workflow, beginning from receiving a key, generating a hash value, converting the hash value into a valid bucket index using the modulo operation, and finally locating the corresponding bucket for performing the requested operation.

Special attention was given to understanding why HashMaps provide average-case constant-time complexity and under what circumstances their performance degrades.

---

### Researching Collision Resolution

Since multiple keys may generate the same bucket index, I studied various collision resolution techniques.

The following approaches were compared:

- Separate Chaining
- Linear Probing
- Quadratic Probing
- Double Hashing

After comparing their advantages and limitations, **Separate Chaining** was selected because it integrates naturally with the previously implemented LinkedList, simplifies insertion and deletion, and scales well even when multiple collisions occur within the same bucket.

---

### Studying Hash Function Design

Considerable time was spent understanding how hash values should be generated for different categories of data types.

The research included:

- Primitive numeric types
- Character types
- Boolean values
- Floating point values
- Strings

For string keys, the **Polynomial Rolling Hash** algorithm was studied in detail to understand how character positions contribute to producing a well-distributed hash value while reducing collisions.

---

### Designing the Internal Architecture

After understanding the hashing mechanism, the internal organization of the HashMap was planned.

The proposed architecture consisted of:

- A **DynamicArray** acting as the bucket table.
- Each bucket storing a pointer to a **LinkedList**.
- Each linked list containing **Node<K, V>** objects representing individual key-value pairs.

The relationship between these components was analyzed to ensure modularity and code reuse while leveraging the previously implemented custom data structures.

---

### Planning Core Data Members

The internal state required for managing the HashMap was identified and finalized.

The following members were selected:

- `bucketArray`
- `size`
- `capacity`
- `loadFactor`
- `threshold`

The purpose of each variable was analyzed along with how it contributes to insertion, deletion, lookup, and automatic resizing.

---

### Initial Configuration Decisions

Several initial configuration values were evaluated before selecting the final configuration.

The following decisions were finalized:

- `size = 0`
- `capacity = 16`
- `loadFactor = 0.0`
- `threshold = 0.7`

Different capacities and threshold values were compared to understand their impact on memory consumption, collision frequency, and rehashing behaviour.

---

### Identifying Design Challenges

Towards the end of the session, one important design challenge was identified.

While designing a generic HashMap using templates, it became clear that generating hash values for **user-defined classes** cannot be automated because the implementation has no way of determining which member uniquely represents an object.

Different approaches were explored, including allowing users to specify the logical key or providing a custom hash function. This issue was documented for further refinement during the design proposal stage.

---

## Outcome

By the end of the session, the complete conceptual architecture of the HashMap had been established. The research covered hashing principles, collision handling, bucket organization, memory considerations, configuration parameters, and generic design challenges. These findings formed the basis for preparing a comprehensive HashMap Design Proposal in the next development session.