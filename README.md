# HFT Low-Latency C++ Roadmap: Week 1
## Memory Optimization & Data Contiguity

### 🎯 Milestone: 16-Byte Order Object
In this phase, I optimized the `Order` class by replacing `std::string` with a scoped `enum`. This reduced the memory footprint of a single order by **60%**, significantly improving CPU cache efficiency.

### 🚀 Key Technical Achievements
* **Enum Class Implementation:** Defined `SIDE` as an enum to replace heap-allocated strings.
* **Memory Footprint Reduction:** Verified via `sizeof(Order)` that the object shrunk from **40 bytes to 16 bytes**.
* **Heap Analysis:** Confirmed via pointer arithmetic that orders are stored contiguously on the heap with exactly a `0x10` (16-byte) offset.
* **Predictable Allocation:** Used `vector::reserve()` to ensure zero reallocations during the "hot loop" of order entry.
* **Zero-Copy Construction:** Refactored `getOrder` to accept a `std::vector<Order>&`.
* **Direct Emplacement:** Switched from returning a temporary object to using `emplace_back(price, quantity, side)`, constructing the object directly in the vector's pre-allocated heap memory.
* **Pass-by-Reference:** Optimized function calls by passing the container by reference, avoiding unnecessary stack copies.

### 📊 Memory Layout (Verified via Output)
- **Order [0]:** `0x10374d930`
- **Order [1]:** `0x10374d940` (Exactly +16 bytes)
- **Cache Efficiency:** 4 Orders now fit into a single 64-byte CPU Cache Line (previously only 1).

### 🛠 How to Build
```bash
clang++ -std=c++17 OrderStorageSystem.cpp -o OrderStorageSystem
./OrderStorageSystem