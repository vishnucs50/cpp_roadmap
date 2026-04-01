# HFT Low-Latency C++ Roadmap: Week 2
## Memory Optimization, Data Contiguity, and Copy Elision

### 🎯 Objective
This project explores the physical memory management of C++ containers. The goal is to achieve "Zero-Copy" order entry by optimizing object size, leveraging CPU cache lines, and utilizing direct heap emplacement.

### 🚀 Key Technical Achievements

#### 1. Memory Footprint Optimization (40B → 16B)
By replacing `std::string` with a scoped `enum class`, I reduced the `Order` object size by **60%**. 
* **Impact:** 4 Orders now fit into a single 64-byte CPU Cache Line (previously only 1 could fit entirely). This drastically reduces Cache Misses during high-frequency scanning.

#### 2. Verification of Heap Contiguity
Using pointer arithmetic, I verified that `std::vector` maintains a perfectly contiguous block of memory.
* **Observation:** Elements are spaced by exactly `0x10` (16 bytes) in hex.

#### 3. Zero-Copy Construction (The `emplace_back` Win)
I implemented a **Custom Copy Constructor** to act as a "detective" to track unnecessary memory duplication.
* **Pass-by-Reference:** Functions accept `std::vector<Order>&` to avoid stack-copying the manager.
* **Direct Emplacement:** Using `emplace_back(price, quantity, side)` constructs the object directly in the reserved heap memory.

---

### 📊 Experimental Results & Output

#### Test A: High-Performance Emplacement (`emplace_back`)
In this test, raw data is passed directly. **Result: 0 Copies.**
```text
Size of the class Order is: 16
Vector location on the stack: 0x16d66ae50
Heap location stored in the vector: 0x102ec1bc0
_________________
Heap address stored in vector : 0x102ec1bc0  <-- Start
Heap address stored in vector : 0x102ec1bd0  <-- +16 Bytes (Perfect alignment)
_________________
++++++ Finished running vector using emplace_back ++++++
```
Test B: Naive Entry (push_back + Return by Value)

In this test, a function returns an object which is then pushed. Result: Multiple Latency-Inducing Copies.
```text
Enter price: 6
Enter Quantity; 2
Buy or Sell? BUY
⚠️ Copy constructor called ⚠️ 

Enter price: 5
Enter Quantity; 1
Buy or Sell? BUY
⚠️ Copy constructor called ⚠️
```
---
### How to build and run
`clang++ -std=c++17 OrderStorageSystem.cpp -o OrderStorageSystem
./OrderStorageSystem`