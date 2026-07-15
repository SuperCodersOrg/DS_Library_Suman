### Build Log – Session 1

**Module:** HashMap Implementation 
**Date:** 10-07-2026
**Duration:** 2 Hours

**Goal:**

* Begin the implementation of the `HashMap` data structure.
* Design the internal bucket representation using `DynamicArray<LinkedList<HashNode<K,V>>*>`.
* Implement the Rule of Three for `HashMap`, including the constructor, destructor, copy constructor, and copy assignment operator.
* Create the `HashNode` class to store key-value pairs.

---

**Problem Encountered:**

* Since each bucket stores a pointer to a `LinkedList`, implementing deep copy required allocating a completely new linked list for every non-empty bucket instead of copying pointers.
* The destructor needed to correctly destroy every dynamically allocated linked list while avoiding memory leaks and dangling pointers.
* Copy assignment required safely releasing all existing buckets before copying data from another `HashMap`, while also handling self-assignment.
* While implementing the copy constructor and assignment operator, ensuring compatibility with the previously implemented `DynamicArray` and `LinkedList` classes required careful consideration of ownership and object lifetime.
* During development, an incorrect template type (`LinkedList<Node<K,V>>`) was accidentally used in one location, which was later corrected to `LinkedList<HashNode<K,V>>`.

---

**What I Tried:**

* Designed a generic `HashNode<K,V>` class containing a key and value along with its own constructor, copy constructor, and destructor.
* Implemented the default constructor of `HashMap` by initializing the hash table with a default capacity of 16, a load factor of `0.0`, a threshold of `0.70`, and populating every bucket with `nullptr`.
* Implemented the destructor to iterate through every bucket, explicitly destroy each allocated `LinkedList<HashNode<K,V>>`, release its memory using `free()`, and reset bucket pointers to `nullptr`.
* Implemented the copy constructor to perform a deep copy by allocating a new linked list for every occupied bucket and invoking the `LinkedList` copy constructor, while preserving empty buckets as `nullptr`.
* Implemented the copy assignment operator by first handling self-assignment, destroying all previously allocated bucket lists, reinitializing the bucket array, copying metadata (`size`, `capacity`, `loadfactor`, and `threshold`), and finally deep-copying every bucket from the source object.
* Verified that the implementation reused the already completed Rule of Three implementations of both `DynamicArray` and `LinkedList`, ensuring ownership was transferred correctly without sharing internal data structures.

---

**Outcome:**

* Successfully completed the initial infrastructure for the `HashMap` class.
* Implemented the complete Rule of Three, ensuring proper memory management and deep-copy semantics for all buckets.
* Integrated the previously implemented `DynamicArray` and `LinkedList` modules into the hash table design.
* Established a solid foundation for implementing the remaining HashMap operations such as hashing, insertion, lookup, deletion, rehashing, and collision handling.

---

**Git Commit:** `8ab4016` — *Implemented Constructor & Rule of Three for HashMap.*

---

### Additional Work Completed (Morning Session)

Apart from implementing the `HashMap`, the following project maintenance and setup tasks were completed:

* Created separate `hashMap.h` and `HashMap.cpp` files following the same project structure as the existing data structures.
* Reviewed and validated the Rule of Three implementations of both `DynamicArray` and `LinkedList` before using them within the `HashMap`.
* Fixed template-related issues in the copy constructor and copy assignment implementation while integrating the bucket structure.
* Configured and built the project using CMake to verify successful compilation after adding the new module.
* Generated the initial build artifacts and successfully committed the completed implementation to the Git repository.