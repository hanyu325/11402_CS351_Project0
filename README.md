# Two Sum
## Description

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers that add up to the target.

You may assume that each input has exactly one solution, and you cannot use the same element twice.

You can return the answer in any order.

## Example

**Input:** `nums = [2,7,11,15], target = 9`  
**Output:** `[0,1]`  
**Explanation:** `nums[0] + nums[1] = 2 + 7 = 9`

## Constraints

- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`

## Requirement

**Language:** C++ with STL vector

**Two Approaches:**

1. **TwoSumArray** - Brute force using nested loops
    - Time Complexity: O(n²)
    - Space Complexity: O(1)

2. **TwoSumHash** - Hash table approach
    - Time Complexity: O(n)
    - Space Complexity: O(n)

### Test Cases

| Input | Target | Expected Output | Description |
|-------|--------|-----------------|-------------|
| `[2,7,11,15]` | `9` | `[0,1]` | Basic case |
| `[3,2,4]` | `6` | `[1,2]` | Different order |
| `[-1,-2,-3,5,7]` | `12` | `[3,4]` | Negative numbers |
| `[1000000,1000000]` | `2000000` | `[0,1]` | Large values |
| `[0,0]` | `0` | `[0,1]` | Edge case with zeros |

## Detail about GitHub Actions

GitHub Actions is a CI/CD platform that automates your software workflow directly in your repository. You can set up automated tests, builds, and deployments triggered by events like push, pull request, or schedule.

**Key Features:**
- **Workflows:** YAML files in `.github/workflows/` that define automation steps
- **Jobs:** Units of work that run on runners (Ubuntu, Windows, macOS)
- **Actions:** Reusable units of code that perform specific tasks
- **Triggers:** Events that start workflow execution (push, pull_request, schedule, etc.)

**Example workflow for C++ testing:**
```yaml
name: C++ Tests
on: [push, pull_request]
jobs:
    build:
        runs-on: ubuntu-latest
        steps:
            - uses: actions/checkout@v3
            - name: Compile
                run: g++ -o twosum twosum.cpp
            - name: Run tests
                run: ./twosum
```

This setup would automatically compile and test your Two Sum solutions on every push or pull request.

### Using CMake

CMake is a build system generator that simplifies compiling C++ projects. Create a `CMakeLists.txt` file in your project root:

```cmake
cmake_minimum_required(VERSION 3.10)
project(TwoSum)

set(CMAKE_CXX_STANDARD 17)

add_executable(twosum twosum.cpp)
```

**Basic workflow:**
1. Create a build directory: `mkdir build && cd build`
2. Generate build files: `cmake ..`
3. Compile: `cmake --build .`
4. Run: `./twosum` (or `twosum.exe` on Windows)

**For GitHub Actions integration, update the workflow:**
```yaml
- name: Configure
    run: cmake -B build
- name: Build
    run: cmake --build build
- name: Run tests
    run: ./build/twosum
```

CMake handles platform differences automatically, making your project portable across operating systems.