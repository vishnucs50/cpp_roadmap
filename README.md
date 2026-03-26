# HFT Low-Latency C++ Roadmap: Week 1
## Order Storage & Memory Analysis

This project is part of a 6-week intensive roadmap focused on building a high-performance **Limit Order Book (LOB)**. Week 1 focuses on C++ memory foundations, specifically how `std::vector` manages heap memory and how to eliminate latency spikes.

### 🎯 Objective
Understand the physical memory layout of C++ objects and the performance implications of dynamic array resizing.

### 🧠 Key Concepts Explored
* **Stack vs. Heap:** Observed the address gap between the vector object (stack) and its underlying data (heap).
* **Predictable Memory:** Used `std::vector::reserve()` to pre-allocate memory, ensuring $O(1)$ insertion time by avoiding expensive reallocations.
* **Memory Alignment:** Analyzed the 40-byte memory offset between `Order` objects to understand compiler padding and data contiguity.
* **Data Contiguity:** Verified that `std::vector` stores elements in a contiguous block, which is essential for CPU cache efficiency.

### 💻 Implementation Details
The `OrderStorageSystem.cpp` performs the following:
1. Defines an `Order` class representing a financial trade.
2. Pre-allocates heap memory for exactly 3 orders.
3. Captures user input on the stack and moves/copies it to the pre-allocated heap space.
4. Outputs the hex memory addresses of each element to verify zero-reallocation behavior.

### 📊 Performance Analysis
In this experiment, the memory address of the first element remained constant:
- **Address of orders[0]:** `0x102f299f0`
- **Address of orders[1]:** `0x102f29a18` (+40 bytes)
- **Address of orders[2]:** `0x102f29a40` (+40 bytes)

By using `reserve(3)`, we ensured that the capacity did not grow, preventing a "stop-the-world" memory copy during the execution loop.

### 🛠 How to Run
```bash
clang++ -std=c++17 OrderStorageSystem.cpp -o OrderStorageSystem
./OrderStorageSystem