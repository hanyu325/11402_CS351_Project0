# Two Sum

## Project Goal

The goal of this project was to implement the classic Two Sum problem in C++. Given an array of integers and a target value, the program finds two numbers whose sum equals the target and returns their indices.

This project also provided experience with software development workflows, including Jira task management, GitHub branches, Pull Requests, GitHub Actions, and CMake.

---

## Problem Description

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers that add up to the target.

You may assume that each input has exactly one solution, and the same element cannot be used twice.

### Example

Input:

```text
nums = [2,7,11,15]
target = 9
```

Output:

```text
[0,1]
```

Explanation:

```text
nums[0] + nums[1] = 2 + 7 = 9
```

---

## Constraints

* `2 <= nums.length <= 10^4`
* `-10^9 <= nums[i] <= 10^9`
* `-10^9 <= target <= 10^9`

---

## Algorithm Idea

Two different approaches were implemented and compared.

### 1. Hash Table Approach

The Hash Table solution uses `unordered_map` to store previously visited values and their indices.

For each element:

1. Calculate the complement value (`target - nums[i]`).
2. Check whether the complement already exists in the hash table.
3. If found, return the two indices.
4. Otherwise, store the current value and continue.

**Time Complexity:** O(n)

**Space Complexity:** O(n)

---

### 2. Sorting + Two Pointers Approach

The Array solution stores each number together with its original index.

1. Create value-index pairs.
2. Sort the pairs by value.
3. Use two pointers from both ends of the sorted array.
4. Move pointers according to the current sum until the target is found.

**Time Complexity:** O(n log n)

**Space Complexity:** O(n)

---

## Development Process

1. Created Jira issues for project planning and implementation.
2. Created feature branches using Jira Issue Keys.
3. Implemented the Two Sum algorithms.
4. Added test cases for validation.
5. Configured CMake for project building.
6. Committed and pushed changes to GitHub.
7. Created Pull Requests for code integration.
8. Verified GitHub Actions checks.
9. Merged approved Pull Requests into the main branch.

---

## Test Cases

| Input             | Target  | Expected Output |
| ----------------- | ------- | --------------- |
| [2,7,11,15]       | 9       | [0,1]           |
| [3,2,4]           | 6       | [1,2]           |
| [-1,-2,-3,5,7]    | 12      | [3,4]           |
| [1000000,1000000] | 2000000 | [0,1]           |
| [0,0]             | 0       | [0,1]           |

### Testing Result

All test cases passed successfully for both implementations.

The program correctly handled:

* Normal cases
* Different index orders
* Negative numbers
* Large integer values
* Edge cases with duplicate values

---

## GitHub Actions

GitHub Actions was used to automate testing and verification whenever code was pushed or a Pull Request was created.

### Benefits

* Automatically builds the project
* Runs tests after each change
* Detects errors early
* Ensures code quality before merging

### Workflow Trigger

```yaml
on:
  - push
  - pull_request
```

This workflow automatically executes whenever code is pushed or a Pull Request is created.

---

## Using CMake

CMake was used as the build system for this project.

### Benefits

* Simplifies project compilation
* Supports multiple operating systems
* Integrates easily with GitHub Actions
* Provides a consistent build process

### Basic Workflow

```text
mkdir build
cd build
cmake ..
cmake --build .
```

CMake automatically generates the required build files and compiles the project.

---

## Project Highlights

* Implemented and compared two algorithm approaches.
* Practiced GitHub Flow using feature branches and Pull Requests.
* Used Jira for task planning and progress tracking.
* Integrated GitHub Actions for automated testing.
* Used CMake for project building and management.

---

## Learning Reflection

Through this project, I learned how to manage a software project using Jira and GitHub instead of only focusing on coding.

I practiced creating feature branches, committing changes, creating Pull Requests, and merging code into the main branch. I also learned how GitHub Actions can automatically test code and how CMake simplifies building C++ projects.

This project helped me better understand a complete software development workflow and improved my experience with AI-assisted software development tools.
