# Session 3: DynamicArray Implementation

## Objective

The objective of this session was to implement the **DynamicArray** template class, which serves as the foundation for other data structures in the project. The primary focus was on implementing dynamic memory management while ensuring proper object lifetime handling and safe copy semantics.

The implementation included:

- Dynamic memory allocation and deallocation.
- Automatic resizing of the array.
- Copy constructor.
- Copy assignment operator.
- Destructor.
- Element insertion and deletion operations.
- Safe handling of object lifetime during resizing and shifting.

---

# Implementation Work

## 1. Designed the Internal Structure

The following private data members were implemented:

- `T* arr` – Pointer to the dynamically allocated array.
- `int size` – Stores the number of elements currently present.
- `int capacity` – Stores the total allocated capacity.

The initial state of the DynamicArray was decided as:

```cpp
size = 0;
capacity = 1;
arr = (T*)malloc(sizeof(T) * capacity);
```

The array automatically increases its capacity whenever it becomes full.

---

## 2. Implemented Dynamic Memory Allocation

Memory for storing elements is allocated dynamically using the heap.

Whenever the current capacity becomes insufficient, a larger memory block is allocated, existing elements are copied into the new array, and the previous memory block is released.

Resizing process:

```
Old Array

Capacity = 4

+---+---+---+---+
| A | B | C |   |
+---+---+---+---+

        │
        ▼

Allocate New Array

Capacity = 8

+---+---+---+---+---+---+---+---+
| A | B | C |   |   |   |   |   |
+---+---+---+---+---+---+---+---+

Delete old memory
```

This approach allows the DynamicArray to grow efficiently while maintaining contiguous memory.

---

## 3. Implemented the Rule of Three

Since the DynamicArray owns dynamically allocated memory, the **Rule of Three** was implemented to prevent shallow copies and memory management issues.

### Destructor

The destructor was implemented to:

- Release dynamically allocated memory.
- Prevent memory leaks.
- Ensure that allocated resources are freed when the object goes out of scope.

### Copy Constructor

A deep copy constructor was implemented.

During implementation, several challenges were encountered:

- Understanding the difference between shallow copy and deep copy.
- Allocating independent memory for the copied object.
- Ensuring both objects manage different memory blocks.
- Preventing multiple objects from deleting the same memory.

### Copy Assignment Operator

The copy assignment operator was implemented to correctly assign one DynamicArray object to another.

The implementation included:

- Checking for self-assignment.
- Releasing previously allocated memory.
- Allocating new memory.
- Copying all elements from the source object.
- Updating `size` and `capacity`.

---

# Problems Faced During Implementation

## 1. Managing Object Lifetime During Element Shifting

One of the most challenging parts of the implementation was deciding how objects should be handled when elements are shifted inside the array.

While implementing insertion and deletion operations, it was necessary to determine:

- When an existing object should be overwritten.
- Whether an explicit destructor call is required.
- Whether assignment alone is sufficient.
- How object lifetime changes after shifting.

Example:

Initial array:

```
Index

0   1   2   3

A   B   C   D
```

Delete element at index **1**:

```
A   C   D
```

After deletion:

- `C` shifts to index `1`.
- `D` shifts to index `2`.
- The last object becomes logically unused.
- `size` decreases by one.

During this process, careful consideration was required to ensure that:

- Objects are not accidentally destroyed twice.
- No memory leaks occur.
- No dangling objects remain.
- Array contents remain valid after shifting.

---

## 2. Implementing `push_back()`

The implementation of `push_back()` required handling multiple situations.

### Normal Case

When sufficient capacity exists:

- Insert the new element.
- Increase `size`.

### Resize Case

When the array becomes full:

- Allocate a larger memory block.
- Copy every existing element into the new array.
- Release the old memory.
- Update the capacity.
- Insert the new element.

The resizing process is illustrated below:

```
Old Array

Capacity = 4

+---+---+---+---+
| A | B | C |   |
+---+---+---+---+

        │
        ▼

New Array

Capacity = 8

+---+---+---+---+---+---+---+---+
| A | B | C | D |   |   |   |   |
+---+---+---+---+---+---+---+---+
```

Special attention was given to:

- Copying all existing elements correctly.
- Releasing old memory only after successful copying.
- Updating internal pointers safely.

---

## 3. Implementing `pop_back()`

The implementation of `pop_back()` required deciding how the last stored object should be removed.

The following aspects were considered:

- Removing the final element.
- Updating the logical size.
- Handling object destruction correctly.
- Maintaining valid array state after deletion.
- Avoiding unnecessary shrinking of capacity.

An important distinction was made between:

- **Logical deletion** (decreasing `size`)
- **Physical memory deallocation** (releasing heap memory)

Since the allocated memory may still be reused for future insertions, reducing the size does not necessarily require releasing the entire allocated block.

---

## 4. Copy Semantics and Memory Safety

Several implementation issues arose while developing copy operations.

These included:

- Preventing shallow copies.
- Ensuring copied objects own separate memory.
- Avoiding double deletion.
- Maintaining exception-safe assignment.
- Preserving data integrity after copying.

Multiple revisions were made before achieving correct ownership and memory management.

---

# Debugging and Improvements

Throughout the implementation, several issues were identified and corrected.

The improvements included:

- Correct implementation of dynamic memory allocation.
- Proper release of allocated memory.
- Correct deep-copy implementation.
- Improved copy assignment logic.
- Better handling of array resizing.
- Correct object shifting during insertion and deletion.
- Prevention of memory leaks.
- Elimination of dangling pointers.
- Validation of object lifetime during copy and destruction.

---

# Outcome

By the end of this session, a functional **DynamicArray** implementation was completed.

The implementation successfully supports:

- Dynamic resizing.
- Safe memory allocation.
- Proper resource management.
- Deep copy semantics.
- Automatic cleanup through the Rule of Three.
- Efficient insertion and deletion operations.

The DynamicArray is now ready to serve as the underlying storage component for higher-level data structures, including the **HashMap** bucket array that will be implemented in subsequent development sessions.