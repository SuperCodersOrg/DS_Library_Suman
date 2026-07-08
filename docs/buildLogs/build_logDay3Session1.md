### Build Log – Session 1

**Project:** Building a Data Structures Library and Redis Lite
**Module:** HashMap Research and Design Analysis
**Date:** 08-07-2026
**Duration:** 2 Hours

## Objective

The objective of this session was to understand the working principles of the **HashMap** data structure before starting its implementation. The focus was on researching how HashMaps store data, generate hash values, resolve collisions, and identifying the essential components required for designing a generic HashMap. This research would later serve as the foundation for preparing the HashMap Design Proposal.

---

## Work Done

### Studying the Fundamentals of HashMap

The session began by understanding how a HashMap stores data as **key-value pairs** and how hashing enables fast insertion, retrieval, deletion, and update operations. I studied how a key is converted into a **hash value**, which is then transformed into a valid bucket index using the modulo operation. I also explored how collisions occur when multiple keys map to the same bucket and why **Separate Chaining** is an effective collision resolution technique.

---

### Researching Hash Value Generation

A major part of the session was spent understanding how hash values are generated for different data types. For primitive numeric types such as `int`, I found that the numeric value itself can be used as the basis for hash generation. For `std::string`, I researched the **Polynomial Rolling Hash** algorithm and learned why it produces a better distribution of hash values than simple character summation.

At this stage, the hashing strategy for primitive data types and strings became clear.

---

### Designing the HashMap Structure

After understanding the hashing mechanism, I researched how the HashMap should be organized internally. I identified the essential data members required for the implementation, including the bucket array, current size, capacity, load factor, and threshold. I also determined that the bucket table would be implemented using the previously developed **DynamicArray**, while collisions would be handled using the custom **LinkedList** through **Separate Chaining**.

---

### Studying Public Member Functions

I analyzed the functionality of every major public operation that the HashMap should provide. This included understanding how `insert()`, `remove()`, `get()`, `exists()`, `getSize()`, `getLoadFactor()`, and `clear()` work internally, what responsibilities each function has, and how they interact with the hashing mechanism and bucket array.

---

### Investigating Initial Design Decisions

Towards the end of the session, I researched appropriate initial configuration values for the HashMap. After comparing different approaches, I concluded that an initial **capacity of 16**, **size of 0**, **load factor of 0.0**, and a **threshold of 0.7** provide a good balance between memory utilization and performance by reducing unnecessary rehashing while maintaining efficient lookup operations.

---

### Identifying an Open Design Problem

Although the overall architecture of the HashMap became much clearer, one important problem remained unresolved. While hash generation for primitive data types and strings was straightforward, I could not determine a generic approach for generating hash values for **user-defined classes**. The HashMap cannot automatically identify which data member should represent the logical key of an object. This challenge was noted for further research in the next development session.

---

## Outcome

By the end of this session, I developed a solid understanding of the HashMap architecture, hashing mechanism, collision handling, required member functions, internal data members, and several key design decisions that would later be documented in the HashMap Design Proposal. However, the problem of supporting hash generation for user-defined data types remained unresolved and became the primary focus for the next session.
