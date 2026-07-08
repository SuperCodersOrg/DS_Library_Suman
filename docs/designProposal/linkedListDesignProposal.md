**Project Title:** Building a Data Structures Library and Redis Lite  
**Student Name:** Suman Mondal  
**Date:** 07 July 2026

# Linked List Design Proposal

This proposal describes the design and implementation of the **Linked List** data structure developed as part of the **Data Structures Library**. It explains the public interface, internal structure, complexity estimates, and key design decisions used during implementation.

The proposal is divided into four sections:

1. **Public API**
2. **Internal Structure**
3. **Complexity Estimates**
4. **Design Decisions**

A **Linked List** is a linear data structure in which elements are stored as individual **nodes**. Each node contains the actual data and a pointer to the next node in the sequence. Unlike arrays, linked list nodes are **not stored in contiguous memory locations**. Instead, they are dynamically allocated and connected through pointers.

Because nodes are allocated individually, the linked list can grow by adding new nodes and shrink by deleting existing nodes. It does not need a fixed capacity like a static array or a resizing strategy like a dynamic array.

The linked list is implemented as a **class template** using `template<typename T>`. This allows the same implementation to store values of any valid C++ type, including primitive types, Standard Library objects, and user-defined classes.

---

# Section 1: Public API

The **Public API** defines the functions available to the user of the `LinkedList` class. It includes insertion, deletion, access, search, traversal, and size-related operations.

The purpose of this API is to make the linked list:

- Simple to use
- Reusable for different data types
- Safe against invalid operations
- Consistent with common data structure interfaces
- Easy to maintain and extend

## Class Structure

```cpp
template<typename T>
class Node {
public:
    T data;
    Node<T>* next;
};

template<typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;

public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);

    void push_front(T val);
    void push_back(T val);
    void pop_front();
    void pop_back();
    void insertAtIndex(int index, T val);
    void deleteAtIndex(int index);
    T& get(int index);
    int search(T val);
    void traverse();
    int getSize();
};
```

The function `get()` returns `T&` so that the caller can access the original stored value directly instead of receiving only a copy.

---

## `push_front(T val)`

The `push_front(T val)` function inserts a new node at the **beginning** of the linked list.

The function allocates memory for a new node. If raw memory is allocated using `malloc()`, placement `new` is used to construct the node or its stored object correctly. The new node's `next` pointer is set to the current head, and then the head pointer is updated to point to the new node.

If the list is empty, the new node automatically becomes the first node. Finally, `size` is incremented.

### Parameter

- **`T val`**: The value used to initialize the new node.

### Return Type

- **`void`**: The function does not return a value.

### Exception Conditions

- Throws **`std::bad_alloc`** if memory allocation fails.

### Time Complexity

- **Best Case:** `O(1)`
- **Average Case:** `O(1)`
- **Worst Case:** `O(1)`

---

## `push_back(T val)`

The `push_back(T val)` function inserts a new node at the **end** of the linked list.

The function first creates a new node. If the list is empty, the new node becomes the head. Otherwise, the function traverses the list until the last node is reached, then updates the last node's `next` pointer to point to the new node.

Finally, `size` is incremented.

### Parameter

- **`T val`**: The value used to initialize the new node.

### Return Type

- **`void`**: The function appends a new node to the list.

### Exception Conditions

- Throws **`std::bad_alloc`** if memory allocation fails.

### Time Complexity

- **Best Case:** `O(1)` when the list is empty
- **Average Case:** `O(n)`
- **Worst Case:** `O(n)`

Here, **`n`** represents the number of nodes in the linked list.

---

## `pop_front()`

The `pop_front()` function removes the first node from the linked list.

If the list is empty, the function throws an exception because no node is available for deletion. Otherwise, a temporary pointer stores the current head node, and the head pointer is updated to the next node.

Before releasing memory, the stored object is destroyed correctly. If placement `new` was used during construction, the destructor must be called explicitly before releasing the raw memory using `free()`. Finally, `size` is decremented.

### Parameter

- **None**

### Return Type

- **`void`**: The function removes the first node.

### Exception Conditions

- Throws **`std::underflow_error`** if deletion is attempted on an empty list.

### Time Complexity

- **Best Case:** `O(1)`
- **Average Case:** `O(1)`
- **Worst Case:** `O(1)`

---

## `pop_back()`

The `pop_back()` function removes the last node from the linked list.

If the list is empty, the function throws an exception. If the list contains only one node, that node is destroyed and freed, `head` is set to `nullptr`, and `size` is decremented.

If the list contains more than one node, the function traverses the list until it reaches the second-last node. The last node is then destroyed, its memory is released, and the second-last node's `next` pointer is set to `nullptr`.

### Parameter

- **None**

### Return Type

- **`void`**: The function removes the last node.

### Exception Conditions

- Throws **`std::underflow_error`** if deletion is attempted on an empty list.

### Time Complexity

- **Best Case:** `O(1)` when the list contains one node
- **Average Case:** `O(n)`
- **Worst Case:** `O(n)`

Here, **`n`** represents the number of nodes in the linked list.

---

## `insertAtIndex(int index, T val)`

The `insertAtIndex(int index, T val)` function inserts a new node at the specified index.

First, the function validates the index. A valid insertion index lies between `0` and `size`, inclusive. If `index == 0`, the function can call `push_front(val)`. If `index == size`, the function can call `push_back(val)`. This avoids duplicate insertion logic and improves maintainability.

For indexes between `1` and `size - 1`, the function traverses the list until it reaches the node immediately before the insertion position. The new node is then linked by updating pointers in the correct order: first the new node points to the next node, then the previous node points to the new node.

### Parameters

- **`int index`**: The position where the new node will be inserted.
- **`T val`**: The value used to initialize the new node.

### Return Type

- **`void`**: The function inserts a new node at the specified index.

### Exception Conditions

- Throws **`std::out_of_range`** if `index < 0` or `index > size`.
- Throws **`std::bad_alloc`** if memory allocation fails.

### Time Complexity

- **Best Case:** `O(1)` when inserting at the beginning
- **Average Case:** `O(n)`
- **Worst Case:** `O(n)`

Here, **`n`** represents the number of nodes in the linked list.

---

## `deleteAtIndex(int index)`

The `deleteAtIndex(int index)` function removes the node stored at the specified index.

First, the function checks whether the index is valid. A valid deletion index lies between `0` and `size - 1`. If `index == 0`, the function can call `pop_front()`. If `index == size - 1`, the function can call `pop_back()`. This reuses existing deletion logic for boundary cases.

For other valid indexes, the function traverses the list until it reaches the node immediately before the target node. The previous node is linked directly to the node after the target node, excluding the target node from the list. The removed node is then destroyed and its memory is released.

### Parameter

- **`int index`**: The position of the node to be removed.

### Return Type

- **`void`**: The function removes the node at the specified index.

### Exception Conditions

- Throws **`std::out_of_range`** if `index < 0` or `index >= size`.
- Throws **`std::underflow_error`** if deletion is attempted on an empty list.

### Time Complexity

- **Best Case:** `O(1)` when deleting the first node
- **Average Case:** `O(n)`
- **Worst Case:** `O(n)`

Here, **`n`** represents the number of nodes in the linked list.

---

## `T& get(int index)`

The `get(int index)` function returns the element stored at the specified index.

Unlike arrays, linked lists do not support direct address calculation using an index. Therefore, the function must traverse the list from the head until the required node is reached.

The function returns a reference (`T&`) instead of a copy. This avoids unnecessary copying and allows the caller to modify the original stored element if required.

### Parameter

- **`int index`**: The position of the element to access.

### Return Type

- **`T&`**: A reference to the element stored at the specified index.

### Exception Conditions

- Throws **`std::out_of_range`** if `index < 0` or `index >= size`.

### Time Complexity

- **Best Case:** `O(1)` when accessing the first node
- **Average Case:** `O(n)`
- **Worst Case:** `O(n)`

Here, **`n`** represents the number of nodes in the linked list.

---

## `int search(T val)`

The `search(T val)` function searches for a specified value in the linked list.

The search starts from the head node and checks each node sequentially. Each stored value is compared with the supplied value using the equality operator (`==`). If a match is found, the function returns the index of the first matching node. If no match is found, it returns `-1`.

### Parameter

- **`T val`**: The value to search for.

### Return Type

- **`int`**: The index of the first matching value, or `-1` if the value is not found.

### Time Complexity

- **Best Case:** `O(1)` when the value is stored at the head node
- **Average Case:** `O(n)`
- **Worst Case:** `O(n)`

Here, **`n`** represents the number of nodes in the linked list.

---

## `void traverse()`

The `traverse()` function visits every node in the linked list and displays each stored element.

Traversal starts from the head and continues by following `next` pointers until the end of the list is reached. The function does not modify the linked list.

### Parameter

- **None**

### Return Type

- **`void`**: The function displays all elements and does not return a value.

### Time Complexity

- **Best Case:** `O(n)`
- **Average Case:** `O(n)`
- **Worst Case:** `O(n)`

Here, **`n`** represents the number of nodes in the linked list.

---

## `int getSize()`

The `getSize()` function returns the current number of nodes in the linked list.

Since the class maintains a separate `size` variable, this function returns that value directly without traversing the list.

### Parameter

- **None**

### Return Type

- **`int`**: The current number of nodes in the linked list.

### Time Complexity

- **Best Case:** `O(1)`
- **Average Case:** `O(1)`
- **Worst Case:** `O(1)`

---

# Section 2: Internal Structure

The **Internal Structure** section explains how the `LinkedList` class is implemented internally and how memory is organized during execution.

The linked list is implemented using two class templates:

- **`Node<T>`**: Represents an individual node.
- **`LinkedList<T>`**: Manages the collection of nodes and provides the public interface.

Each node contains:

- A data member of type `T`, which stores the actual value.
- A pointer named `next`, which stores the address of the next node.

The `LinkedList` class maintains:

- **`Node<T>* head`**: Points to the first node of the linked list.
- **`int size`**: Stores the current number of nodes.

Initially, `head` is set to `nullptr`, which means the list is empty. When a new node is inserted, memory is allocated dynamically. Since nodes are allocated independently, linked list elements are not stored in contiguous memory locations.

During deletion, the target node is disconnected from the list, its stored object is destroyed correctly, and its memory is released. Unlike a Dynamic Array, the linked list does not have a capacity variable and does not require a shrinking strategy. Deleting a node directly frees that node's memory.

## Memory Layout
![Linked List Memory Layout](../Images/LinkedListMemoryLayout.jpeg)

## Template Concept and Generic Type

The linked list is implemented using `template<typename T>`. Here, `T` is a placeholder for the actual data type that will be used when an object is created.

For example:

```cpp
LinkedList<int> numbers;
LinkedList<double> prices;
LinkedList<std::string> names;
```

This is called **generic programming**. It avoids writing separate linked list classes for different data types. The same code can work with primitive types, Standard Library types, and user-defined classes.

The type `T` is resolved at compile time, so the implementation remains type-safe while still being reusable.

## Object-Oriented Programming Principles Used

The implementation uses the following OOP principles:

- **Encapsulation:** `head` and `size` are private, so users cannot directly modify the internal state.
- **Abstraction:** Users call functions such as `push_front()`, `insertAtIndex()`, and `deleteAtIndex()` without needing to manage pointers manually.
- **Modularity:** Each operation is implemented as a separate member function with a clear responsibility.
- **Code Reuse:** `insertAtIndex()` can reuse `push_front()` and `push_back()` for boundary insertions. `deleteAtIndex()` can reuse `pop_front()` and `pop_back()` for boundary deletions.

Inheritance and polymorphism are not required because this data structure mainly focuses on efficient node management and a clean container interface.

## Rule of Three

Since the linked list manages dynamically allocated memory, it follows the **Rule of Three**:

1. **Destructor**
2. **Copy Constructor**
3. **Copy Assignment Operator**

### Destructor

The destructor traverses the entire list, destroys each node, and releases its memory. This prevents memory leaks when the linked list object goes out of scope.

### Copy Constructor

The copy constructor performs a **deep copy** of the source list. Instead of copying node addresses, it creates new nodes for every element. As a result, both linked lists own independent memory.

### Copy Assignment Operator Overloading

The copy assignment operator overloading first releases the memory currently owned by the destination list. It then performs a deep copy of the source list. It should also handle self-assignment safely. This prevents shallow copying, dangling pointers, memory leaks, and double deletion.

---

# Section 3: Complexity Estimates

The following table summarizes the time complexity of each public member function.

| Function | Best Case | Average Case | Worst Case | Reason |
|---|---:|---:|---:|---|
| `push_front()` | `O(1)` | `O(1)` | `O(1)` | Only updates the new node and head pointer. |
| `push_back()` | `O(1)` | `O(n)` | `O(n)` | Traverses to the last node unless the list is empty. |
| `insertAtIndex()` | `O(1)` | `O(n)` | `O(n)` | Boundary insertion is constant; middle insertion requires traversal. |
| `pop_front()` | `O(1)` | `O(1)` | `O(1)` | Only updates the head pointer. |
| `pop_back()` | `O(1)` | `O(n)` | `O(n)` | Traverses to the second-last node unless only one node exists. |
| `deleteAtIndex()` | `O(1)` | `O(n)` | `O(n)` | Boundary deletion is constant; middle deletion requires traversal. |
| `get()` | `O(1)` | `O(n)` | `O(n)` | Traverses from the head to the required index. |
| `search()` | `O(1)` | `O(n)` | `O(n)` | Checks nodes sequentially until a match is found. |
| `traverse()` | `O(n)` | `O(n)` | `O(n)` | Visits every node once. |
| `getSize()` | `O(1)` | `O(1)` | `O(1)` | Directly returns the stored size value. |

## Complexity Analysis

The linked list provides efficient insertion and deletion at the beginning because only the head pointer needs to be updated. However, operations at the end or at a specific index may require traversal because a singly linked list does not provide direct access to arbitrary positions.

Accessing an element by index takes `O(n)` time because the list must be traversed from the head node. Searching also takes `O(n)` in the average and worst cases because each node may need to be checked.

Maintaining the `size` variable allows `getSize()` to run in `O(1)` time.

---

# Section 4: Design Decisions

This section explains the major design decisions taken during the implementation of the Linked List. For every important design choice, alternative approaches were considered before selecting the most appropriate one. The objective was to build a generic, reusable, memory-efficient, and easy-to-maintain data structure.

---

## 1. Generic Programming Using Templates

### Selected Design

The Linked List is implemented using a **class template** (`template<typename T>`).

### Alternative Considered

Creating separate implementations for every data type, such as:

- `LinkedList<int>`
- `LinkedList<float>`
- `LinkedList<string>`

### Reason for Rejection

Maintaining separate implementations would introduce significant code duplication. Every modification or bug fix would have to be repeated for each data type, increasing development and maintenance effort.

### Reason for Selection

Templates allow a single implementation to work with any data type while preserving compile-time type safety. This improves code reusability, maintainability, and scalability without sacrificing performance.

---

## 2. Separate Node Class

### Selected Design

Each element of the linked list is represented by an independent `Node<T>` object.

### Alternative Considered

Embedding node-related logic directly inside the `LinkedList` class without a dedicated node representation.

### Reason for Rejection

Combining storage and list management responsibilities would reduce modularity and make the implementation more difficult to understand and maintain.

### Reason for Selection

Separating the `Node` class from the `LinkedList` class follows the **Single Responsibility Principle (SRP)**. Each node stores data and the link to the next node, while the linked list manages insertion, deletion, traversal, and other operations.

---

## 3. Singly Linked List over Doubly Linked List

### Selected Design

A **Singly Linked List** was chosen for this implementation.

### Alternative Considered

A **Doubly Linked List**, where every node stores both `next` and `previous` pointers.

### Reason for Rejection

Although a doubly linked list supports reverse traversal and simplifies certain deletion operations, it requires an additional pointer in every node. This increases memory consumption and makes insertion and deletion logic more complex because both forward and backward links must always remain consistent.

The objectives of this project do not require reverse traversal or bidirectional navigation. Therefore, the additional memory overhead and implementation complexity cannot be justified.

### Reason for Selection

A singly linked list satisfies all project requirements while maintaining a simpler design. Since each node stores only one pointer, the implementation is easier to understand, requires less memory, and reduces the possibility of pointer-related programming errors.

---

## 4. Dynamic Memory Allocation

### Selected Design

Each node is allocated dynamically whenever a new element is inserted.

### Alternative Considered

Using a fixed-size array to store all elements.

### Reason for Rejection

A fixed-size array requires the maximum size to be decided before execution. Once the array becomes full, no additional elements can be inserted without reallocating the entire structure.

### Reason for Selection

Dynamic allocation allows the linked list to grow and shrink according to runtime requirements. Memory is allocated only when a new node is required and is released immediately after a node is deleted.

If raw memory is allocated using `malloc()`, placement `new` is used to construct C++ objects correctly. During deletion, the object's destructor is explicitly invoked before releasing memory using `free()`.

---

## 5. No Capacity Management

### Selected Design

The linked list does **not** maintain a capacity variable.

### Alternative Considered

Maintaining capacity, resizing policies, and shrinking strategies similar to a Dynamic Array.

### Reason for Rejection

Unlike a dynamic array, linked list nodes are allocated individually instead of inside one contiguous memory block. Consequently, there is no concept of unused capacity.

### Reason for Selection

Each insertion allocates memory only for the required node, and each deletion immediately releases the corresponding memory. This naturally allows the linked list to expand and contract without implementing resizing algorithms.

---

## 6. Maintaining a Size Variable

### Selected Design

The implementation maintains a dedicated integer variable named `size`.

### Alternative Considered

Calculating the size by traversing the linked list whenever `getSize()` is called.

### Reason for Rejection

Computing the size through traversal requires visiting every node, resulting in **O(n)** time complexity.

### Reason for Selection

Updating the `size` variable after every insertion and deletion allows the current number of nodes to be returned in **O(1)** time.

---

## 7. Returning a Reference from `get()`

### Selected Design

The `get()` function returns a reference (`T&`).

### Alternative Considered

Returning the stored value by copy.

### Reason for Rejection

Returning a copy introduces unnecessary copying overhead, particularly for large user-defined objects, and prevents direct modification of the original element.

### Reason for Selection

Returning a reference avoids unnecessary copying and allows efficient access to the original object stored inside the linked list.

---

## 8. Exception Handling

### Selected Design

Standard C++ exceptions are used to report invalid operations.

### Alternative Considered

Returning special values such as `-1`, `NULL`, or boolean flags.

### Reason for Rejection

Special return values may not accurately describe the cause of an error and can easily be ignored by the caller.

### Reason for Selection

Using exceptions separates normal program logic from error-handling logic and provides meaningful information about the failure.

The implementation uses:

- `std::out_of_range` for invalid indexes.
- `std::underflow_error` when deletion is attempted on an empty list.
- `std::bad_alloc` if memory allocation fails.

---

## 9. Deep Copy Semantics

### Selected Design

The linked list implements a copy constructor and copy assignment operator that perform a **deep copy**.

### Alternative Considered

Using the compiler-generated shallow copy.

### Reason for Rejection

A shallow copy causes multiple linked lists to share the same nodes. When one object destroys those nodes, the remaining objects contain dangling pointers, leading to undefined behavior and possible double deletion.

### Reason for Selection

Deep copying creates independent nodes for every linked list object, ensuring safe ownership and correct memory management.

---

## 10. Function Reuse

### Selected Design

Common operations are reused instead of duplicating logic.

### Examples

- `insertAtIndex(0, val)` calls `push_front(val)`.
- `insertAtIndex(size, val)` calls `push_back(val)`.
- `deleteAtIndex(0)` calls `pop_front()`.
- `deleteAtIndex(size - 1)` calls `pop_back()`.

### Reason for Selection

Function reuse reduces duplicate code, improves readability, simplifies testing, and ensures that changes made to one operation automatically benefit all functions that depend on it.

---

## 11. Choosing Linked List over Dynamic Array

### Selected Design

A Linked List was selected for implementing this project instead of extending the Dynamic Array.

### Reason for Selection

The linked list provides efficient insertion and deletion without shifting existing elements, making it suitable for applications where structural modifications occur frequently.

### Trade-off

The primary limitation of a linked list is that indexed access requires sequential traversal because nodes are not stored in contiguous memory locations. Therefore, random access is slower than in a Dynamic Array.

This trade-off is acceptable because the primary objective of this implementation is to demonstrate efficient node-based insertion, deletion, and dynamic memory management.