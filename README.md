# AutoClickers
The same auto clicker in multiple languages for better performance and efficiency.

## Comparison table between all current Auto Clickers (best of three [tests of 10 seconds](https://cpstest.org/).
| Rank | Script Name                | CPS   | Max CPU Utilization | RAM Usage |
|------|----------------------------|-------|---------------------|-----------|
| 1    | auto_28ms.c                | 26.2  | 0.3%                | 6.8 MB    |
| 2    | auto_multi_threading.cpp   | 26    | 0.1%                | 7 MB      |
| 3    | auto.js                    | 25.8  | 0%                  | 0.8 MB    |

Note: This can vary from system to system, and different settings inside each script may produce different results. Changing the 28ms interval in each auto clicker will affect the results considerably. 


## Install files (all Auto Clickers)
```bash
git clone https://github.com/AntoniiP/AutoClickers .
```
## Requirements for C and C++ Auto Clickers:
- GCC
  
## Compile C++ Auto Clickers
1. Change directory
```bash
cd C++
```
2. Compile the desired Auto Clicker:
- Multithreading with 28ms delay:
```bash
g++ -O3 -march=native -mtune=native -pthread -std=c++11 -o AutoClicker auto_multi_threading.cpp
```
Explanation of flags:

- `-O3`: Enables aggressive optimization levels.
- `-march=native`: Generates code optimized for the host machine's architecture.
- `-mtune=native`: Optimizes code for the host machine's microarchitecture.
- `-pthread`: Links the pthread library for multithreading support.
- `-std=c++11`: Specifies the C++ version to use (you can use a higher version if your compiler supports it).
- `-o AutoClicker`: Specifies the output executable file.

Note: This optimization on efficiency and performance this aggressively might not always yield better performance and could introduce unexpected behaviour based on multiple factors, such as specific hardware. 

## Compile C Auto Clicker
1. Change directory
```bash
cd C
```
2. Compile the desired Auto Clicker:
- Auto Clicker with 28ms delay:
```bash
gcc -O2 -march=native -funroll-loops -s -o AutoClicker.exe auto_28ms.c
```
- `-O2`: This flag optimizes the code for speed without increasing the compilation time too much. It enables most optimizations.
- `-march=native`: This tells the compiler to generate code optimized for the specific architecture of your machine.
- `-funroll-loops`: This can unroll loops for a slight performance increase.
- `-s`: This option strips the executable, removing all symbol table and relocation information from the executable, reducing file size; even though it's unnecessary.

## Requirements for JS Auto Clicker:
- Node.js version 18.17.1+

## Run JS Auto Clicker
1. Change directory
```bash
cd JS
```
2. Install dependencies and run Auto Clicker:
```bash
npm i
```
```bash
node .
```

