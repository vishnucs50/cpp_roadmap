# HFT Low-Latency C++ Roadmap: Week 1 (Updated)
## Memory Optimization & Object-Oriented Refactoring

### 🎯 Objective
Refactor the Order Storage system to use custom types (Enums) and evaluate the impact of data types on memory footprint and cache-friendliness.

### 🚀 Key Improvements
* **Enum Conversion:** Replaced `std::string` with `enum class SIDE`. 
    * *Result:* Reduced `Order` object size from **40 bytes** to **16 bytes**.
* **OOP Structure:** Encapsulated logic within the `Order` class, moving toward a more professional architecture.
* **Emplacement Logic:** Utilized `emplace_back` to signal intent for in-place construction (preparing for Week 2 move semantics).

### 📊 Memory Analysis (Post-Optimization)
By moving from a string to an enum, the memory offset between elements shrunk significantly:
- **Order [0] at:** `0x100e69b60`
- **Order [1] at:** `0x100e69b70` (+16 bytes)
- **Order [2] at:** `0x100e69b80` (+16 bytes)

This 60% reduction in object size allows for significantly better cache utilization and lower memory bandwidth usage.

### 🛠 How to Run
```bash
clang++ -std=c++17 OrderStorageSystem.cpp -o OrderStorageSystem
./OrderStorageSystem