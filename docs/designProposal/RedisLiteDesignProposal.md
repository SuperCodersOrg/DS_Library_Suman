**Project Title:** Building a Data Structures Library and Redis Lite    
**Date:** 15-07-2026

# Redis Lite Design Proposal

Redis Lite is a lightweight in-memory key-value database developed as the application component of the **Data Structures Library** project. Unlike the previously implemented modules such as **DynamicArray**, **LinkedList**, and **HashMap**, Redis Lite is not a new data structure. Instead, it demonstrates how multiple reusable data structures can be integrated to develop a practical software application.

Redis Lite provides an interactive command-line interface that allows users to perform basic database operations, including storing, retrieving, deleting, searching, and counting key-value pairs. The application accepts commands from the user, interprets them, executes the corresponding operation on the underlying data structures, and displays the result immediately. Since all data is maintained in main memory, Redis Lite provides fast data access while keeping the implementation simple and efficient.

The storage engine of Redis Lite is built entirely on the custom **HashMap** implementation developed earlier in this project. The HashMap internally utilizes the custom **DynamicArray** for bucket management and **LinkedList** for collision resolution using separate chaining. Consequently, Redis Lite serves as a practical application that validates the correctness, efficiency, and reusability of every data structure implemented throughout this project.

The application follows a layered architecture that clearly separates user interaction, command processing, and data storage. The command-line interface is responsible for receiving user input and displaying results, while the Redis Lite engine interprets commands and delegates all database operations to the underlying HashMap. This separation of responsibilities improves modularity, maintainability, and extensibility, making it easier to introduce additional database commands and features in future versions.

After initialization, Redis Lite continuously accepts commands from the user, performs the requested operations on the underlying HashMap, and displays the corresponding results. The application continues executing until the user terminates the session using the `EXIT` command.

The primary objective of Redis Lite is not to replicate every feature of the original Redis database. Instead, the project focuses on designing a clean, modular, and efficient command-driven key-value database that demonstrates the practical application of the custom data structures implemented throughout this project.

This proposal is divided into the following four sections:

1. Public API
2. Internal Representation
3. Complexity Estimates
4. Design Decisions


# Section 1: Public API

The **Public API** defines the member functions that collectively implement the behavior of the `RedisLite` class. Unlike the previously developed data structures, Redis Lite is an application rather than a reusable container. Consequently, most of its functionality is implemented through private member functions that cooperate internally to process user commands and perform database operations.

The class provides a single public function, `run()`, which starts the command-processing loop and serves as the entry point of the application. During execution, the `run()` function continuously accepts commands from the user, interprets them, and delegates the requested operation to the appropriate private member function.

The private member functions encapsulate individual database operations such as insertion, retrieval, deletion, existence checking, counting, displaying all stored records, and clearing the database. Each of these functions communicates directly with the underlying `HashMap` object, allowing the command-processing logic to remain separate from the storage mechanism.

This separation of responsibilities improves readability, modularity, and maintainability while making it easier to extend Redis Lite with additional commands in future versions.

## Class Structure

```cpp
class RedisLite
{
private:

    HashMap<string, string> store;

    string toLower(const string& str);

    void set(string key, string value);
    void get(string key);
    void del(string key);
    void exists(string key);
    void count();
    void clear();
    void show();

public:

    RedisLite();

    void run();
};
```

The `HashMap` object named `store` represents the internal database used to store all key-value pairs during program execution. Every database command ultimately translates into one or more operations performed on this object.

The `run()` function is the only public member function because it acts as the application's execution entry point. All remaining member functions are declared private since they are intended to be invoked only by the command-processing logic within the `RedisLite` class and should not be accessible directly from outside the class.

---

## `RedisLite()`

The default constructor initializes the Redis Lite object.

During object construction, the internal `HashMap` object is automatically constructed, creating an empty in-memory database that is ready to store key-value pairs. No additional initialization is required because the `HashMap` constructor is responsible for preparing its internal data structures.

### Parameters

- None

### Return Type

- None

### Exception Conditions

- Any exception thrown during the construction of the internal `HashMap` object is propagated to the caller.

### Time Complexity

- **Best Case:** `O(1)`
- **Average Case:** `O(1)`
- **Worst Case:** `O(1)`

---

## `void run()`

The `run()` function starts the interactive execution of Redis Lite.

The function repeatedly displays the command prompt, accepts an entire line of input from the user using `getline()`, separates the command into individual tokens, normalizes the command name to support case-insensitive command recognition, validates the supplied arguments, and invokes the corresponding private member function.

Each private member function performs the requested operation on the internal `HashMap`. After execution, the result is formatted and displayed to the user before the application waits for the next command.

The command-processing loop continues until the user enters the `EXIT` command.

### Parameters

- None

### Return Type

- `void`

### Exception Conditions

- The function handles invalid commands and incorrect arguments internally by displaying appropriate error messages.

### Time Complexity

- Depends upon the command being executed.

---

## `string toLower(const string& str)`

The `toLower()` function converts the command name into lowercase characters before command validation.

Only the command keyword is normalized, while keys and values remain unchanged. This allows Redis Lite to support case-insensitive commands without modifying user data.

### Parameters

- **`const string& str`** : Command entered by the user.

### Return Type

- **`string`** : Lowercase representation of the command.

### Exception Conditions

- None.

### Time Complexity

- **Best Case:** `O(m)`
- **Average Case:** `O(m)`
- **Worst Case:** `O(m)`

where **`m`** is the length of the command string.

---

## Command Processing Functions

The following private member functions implement the database commands supported by Redis Lite.

| Function | Purpose |
|----------|---------|
| `set(string key, string value)` | Inserts a new key-value pair into the database or updates the value if the key already exists. |
| `get(string key)` | Retrieves and displays the value associated with the specified key. |
| `del(string key)` | Removes the specified key-value pair from the database. |
| `exists(string key)` | Determines whether the specified key exists in the database. |
| `count()` | Displays the total number of key-value pairs currently stored in the database. |
| `show()` | Displays every key-value pair currently stored in the database in a tabular format. |
| `clear()` | Removes all key-value pairs from the database. |

The `show()` function traverses the entire database and displays every stored record in a structured tabular format.

Example output:

```text
redis-lite> SHOW

Key        Value
-----------------------
name       Suman
age        22
city       Hisar
```

These functions are declared as private because they form the internal implementation of the Redis Lite engine. They are invoked only after the user command has been successfully parsed and validated by the `run()` function, ensuring that the application's internal operations remain encapsulated from external users.

---

# Section 2: Internal Representation

The **Internal Representation** section describes the internal organization of Redis Lite and the interaction between its components. Unlike the previously implemented modules, Redis Lite does not implement a new data structure. Instead, it acts as an application layer that interprets user commands and delegates all database operations to the underlying `HashMap`.

Internally, Redis Lite maintains a single `HashMap` object named `store`, which serves as the in-memory database. All key-value pairs are stored inside this object, while the remaining member functions are responsible for command processing and user interaction.

---

## Class Components

### Storage Engine

```cpp
HashMap<string, string> store;
```

The `store` object represents the complete in-memory database. Every database command ultimately translates into an operation performed on this `HashMap`.

---

### Command Processing Functions

Redis Lite provides dedicated private member functions for each supported database command.

```cpp
void set(string key, string value);
void get(string key);
void del(string key);
void exists(string key);
void count();
void show();
void clear();
```

Each function communicates with the internal `HashMap` to perform the corresponding database operation.

---

### Command Normalization

Before command validation, the command name is converted into lowercase using the `toLower()` function. This enables case-insensitive command recognition while preserving the original case of keys and values.

---

## Memory Organization

![RedisLite Memory Layout](../Images/RedisLiteMemoryLayout.jpeg)

---

## Command Processing Workflow

Every command entered by the user passes through the following stages before execution.

```text
User
   │
   ▼
Command Line Interface → getline() → stringstream → Token Vector → toLower() → Command Validation → Private Member Function → HashMap → Formatted Output
```

---

## Command Execution

After successful validation, Redis Lite invokes the appropriate private member function, which performs the corresponding operation on the internal `HashMap`.

| User Command | Private Function | HashMap Function |
|--------------|------------------|------------------|
| `SET` | `set()` | `insert()` |
| `GET` | `get()` | `get()` |
| `DEL` | `del()` | `remove()` |
| `EXISTS` | `exists()` | `exists()` |
| `COUNT` | `count()` | `getSize()` |
| `SHOW` | `show()` | `printBuckets()` |
| `CLEAR` | `clear()` | `clear()` |

This layered design separates command processing from data storage, improving modularity and maintainability.

---

## Output Generation

After the requested operation completes, Redis Lite formats the result before displaying it to the user.

Example:

```text
redis-lite> SHOW

Key        Value
-----------------------
name       Suman
age        22
city       Hisar
```

Invalid commands or incorrect arguments produce appropriate error messages without terminating the application.

---

## Object Lifetime

The execution lifecycle of Redis Lite is illustrated below.

```text
main()
    │
    ▼
RedisLite() → HashMap() → run() → Command Processing Loop → EXIT → run() Returns → ~RedisLite() → ~HashMap() → Program Ends
```

The `HashMap` object is automatically constructed when the `RedisLite` object is created and automatically destroyed when the application terminates, ensuring proper resource management.


# Section 3: Complexity Estimates

The time complexity of Redis Lite commands primarily depends on the complexity of the corresponding operations performed by the underlying `HashMap`. Since the HashMap provides average constant-time access through hashing, most Redis Lite commands also execute in constant time under normal operating conditions.

| Command | HashMap Operation | Best Case | Average Case | Worst Case |
|----------|-------------------|-----------|--------------|------------|
| `SET` | `insert()` | **O(1)** | **O(1)** | **O(n)** |
| `GET` | `get()` | **O(1)** | **O(1)** | **O(n)** |
| `DEL` | `remove()` | **O(1)** | **O(1)** | **O(n)** |
| `EXISTS` | `exists()` | **O(1)** | **O(1)** | **O(n)** |
| `COUNT` | `getSize()` | **O(1)** | **O(1)** | **O(1)** |
| `SHOW` | `printBuckets()` | **O(n)** | **O(n)** | **O(n)** |
| `CLEAR` | `clear()` | **O(n)** | **O(n)** | **O(n)** |

Where **n** represents the total number of key-value pairs stored in the database.

The `SET`, `GET`, `DEL`, and `EXISTS` commands rely on hash-based lookup and therefore execute in constant time under normal conditions. Their worst-case complexity becomes linear only when excessive hash collisions occur.

The `COUNT` command simply returns the number of stored entries maintained by the HashMap and therefore executes in constant time.

The `SHOW` and `CLEAR` commands must visit every stored key-value pair, resulting in linear time complexity.

---

# Section 4: Design Decisions

This section discusses the major design decisions taken during the implementation of Redis Lite along with the alternatives that were considered.

---

## Design Decision 1: Interactive Command-Line Interface

### Selected Design

Redis Lite is implemented as an interactive command-line application where users enter commands continuously until the `EXIT` command is issued.

### Alternative Considered

A graphical user interface or a file-based command processor.

### Reason for Selection

A command-line interface closely resembles the original Redis client, simplifies implementation, and allows users to interact with the database in real time.

---

## Design Decision 2: HashMap as the Storage Engine

### Selected Design

All key-value pairs are stored using the custom `HashMap<string, string>` implementation.

### Alternative Considered

Using the C++ Standard Library `std::unordered_map`.

### Reason for Selection

Using the custom HashMap demonstrates the practical application of the previously implemented data structures while validating their correctness and performance.

---

## Design Decision 3: String-Based Key-Value Storage

### Selected Design

Redis Lite stores both keys and values as `std::string` objects.

```cpp
HashMap<string, string> store;
```

### Alternative Considered

Using different data types for values, such as integers, floating-point numbers, or generic objects.

### Reason for Rejection

Redis Lite accepts commands through a command-line interface, where every user input is initially received as text. Since the command parser cannot directly distinguish between integers, floating-point numbers, characters, or strings, supporting multiple data types would require additional parsing, type detection, and conversion logic, unnecessarily increasing the complexity of the implementation.

### Reason for Selection

Using `HashMap<string, string>` provides a simple and consistent storage model because every key and value received from the command-line interface is naturally represented as a string. This eliminates unnecessary type conversion, simplifies command processing, and keeps the implementation focused on the core functionality of a lightweight key-value database.

---

## Design Decision 4: Case-Insensitive Command Recognition

### Selected Design

Only the command name is converted into lowercase before validation.

Example:

```text
SET
Set
sEt
set
```

are all interpreted as the same command.

### Alternative Considered

Treating commands as case-sensitive.

### Reason for Selection

Case-insensitive commands improve usability while preserving the original capitalization of user keys and values.

---

## Design Decision 5: Separation of Command Processing and Data Storage

### Selected Design

Redis Lite performs only command parsing and user interaction. All storage-related operations are delegated to the underlying HashMap.

### Alternative Considered

Implementing storage operations directly inside the Redis Lite class.

### Reason for Selection

Separating command processing from data storage improves modularity, code reuse, and maintainability.

---

## Design Decision 6: Dedicated Member Function for Every Command

### Selected Design

Each supported command is implemented as an individual private member function.

```cpp
set()
get()
del()
exists()
count()
show()
clear()
```

### Alternative Considered

Implementing all commands inside the `run()` function.

### Reason for Selection

Separate functions improve readability, simplify debugging, and make future extensions easier.

---

## Design Decision 7: Command Parsing Using `stringstream`

### Selected Design

Redis Lite uses `std::stringstream` to tokenize user input.

### Alternative Considered

Manual character-by-character parsing.

### Reason for Selection

`stringstream` provides a simple, reliable, and maintainable mechanism for separating commands and arguments while automatically handling multiple spaces.

---

## Design Decision 8: Tabular Output for Database Display

### Selected Design

The `SHOW` command displays all stored key-value pairs in a structured table.

Example:

```text
redis-lite> SHOW

Key        Value
-----------------------
name       Suman
age        22
city       Hisar
```

### Alternative Considered

Displaying one key-value pair per line without formatting.

### Reason for Selection

A tabular format improves readability, especially when the database contains many records.

---

## Design Decision 9: Object-Oriented Architecture

### Selected Design

Redis Lite is implemented as a class that encapsulates the command-processing logic and owns a single `HashMap` object.

### Alternative Considered

Using global variables and standalone functions.

### Reason for Selection

Encapsulation improves maintainability, reduces global state, and provides a clean separation between the application layer and the storage layer.