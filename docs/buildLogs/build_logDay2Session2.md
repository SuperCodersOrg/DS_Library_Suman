# Build Log

**Project Title:** Building a Data Structures Library and Redis Lite  
**Student Name:** Suman Mondal
**Date:** 06 July 2026 
---
# Session 2

**Duration:** 2 Hours

### Goal

Finalize the design decisions for Dynamic Array and analyze the computational complexity of every public operation.

The objectives were:

- Determine the complexity of each API.
- Justify the resizing strategy.
- Decide how memory should grow when capacity becomes full.
- Document implementation decisions before coding.

---

### Problem Encountered

The biggest challenge during this session was explaining why `push_back()` has **O(1) amortized** complexity even though resizing requires copying all existing elements.

At first glance, resizing appears to make insertion an **O(n)** operation.

Another difficulty was selecting an appropriate capacity growth strategy.

Possible options included:

- Increase by one element
- Increase by a fixed number
- Increase by a multiplication factor

Each approach has different trade-offs between runtime performance and memory utilization.

---

### What I Tried

I analyzed the behavior of Dynamic Arrays during repeated insertions.

Instead of increasing capacity by one element every time, I chose the **capacity doubling strategy**.

I mathematically analyzed the resizing process.

After every resize:

- Capacity doubles.
- The number of resizing operations after inserting `n` elements becomes **O(log n)**.
- The total number of copied elements forms the geometric progression:

```
1 + 2 + 4 + 8 + ... + n/2
```

which sums to:

```
n - 1
```

Therefore, the total work performed during `n` insertions becomes approximately:

```
2n - 1
```

This proves that the average cost of each insertion remains constant, giving **O(1) amortized** complexity.

I also estimated the complexity of every remaining API and documented the reasoning behind each complexity value.

Finally, I added implementation decisions regarding:

- Rule of Three
- contiguous memory allocation
- template-based generic programming
- encapsulation
- exception handling
- automatic resizing strategy

---

### Outcome

The Dynamic Array design proposal was completed with all four major sections:

- Public API
- Internal Representation
- Complexity Estimates
- Design Decisions

The resizing strategy is now mathematically justified instead of being based only on intuition.

I also gained a much deeper understanding of why Dynamic Arrays provide constant-time random access while insertion and deletion in the middle require linear time due to element shifting.

The proposal is now sufficiently detailed to begin the actual implementation phase with a clear understanding of both the data structure and its design trade-offs.