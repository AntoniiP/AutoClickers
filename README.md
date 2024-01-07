# AutoClickers
The same auto clicker in multiple languages for better performance.

## Install files (all Auto Clickers)
```bash
git clone https://github.com/AntoniiP/AutoClickers .
```
## Requirements for C++ Auto Clickers:
- GCC
  
## Compile C++ Auto Clickers
```bash
cd C++
```
```bash
g++ -O3 -march=native -mtune=native -pthread -std=c++11 -o AutoClicker auto_multi_threading.cpp
```
Explanation of flags:

- -O3: Enables aggressive optimization levels.
- -march=native: Generates code optimized for the host machine's architecture.
- -mtune=native: Optimizes code for the host machine's microarchitecture.
- -pthread: Links the pthread library for multithreading support.
- -std=c++11: Specifies the C++ version to use (you can use a higher version if your compiler supports it).
- -o AutoClicker: Specifies the output executable file.

Note: This optimization on efficiency and performance this aggressively might not always yield better performance and could introduce unexpected behaviour based on multiple factors, such as specific hardware. 
