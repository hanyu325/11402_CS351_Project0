#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class TwoSumSolver {
public:
    // Approach 1: Brute force approach using nested loops
    static std::vector<int> TwoSumArray(const std::vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        // Guaranteed exactly one solution by constraints, so this is just a fallback.
        return {}; 
    }

    // Approach 2: Optimized approach using a hash table
    static std::vector<int> TwoSumHashTable(const std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int complement = target - nums[i];
            
            // Check if the complement already exists in the hash map
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            // Store the current number and its index in the hash map
            numMap[nums[i]] = i;
        }
        return {}; 
    }
};

// --- Output Utilities ---

// Helper function to format and print a vector
void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << (i == vec.size() - 1 ? "" : ", ");
    }
    std::cout << "]";
}

// Helper function to execute and print the test case output
void runTest(const std::string& testName, const std::vector<int>& nums, int target) {
    std::cout << "--- " << testName << " ---\n";
    
    // 取得 Approach 1 的結果並印出
    std::vector<int> res1 = TwoSumSolver::TwoSumArray(nums, target);
    std::cout << "TwoSumArray Output:     ";
    printVector(res1);
    std::cout << "\n";
    
    // 取得 Approach 2 的結果並印出
    std::vector<int> res2 = TwoSumSolver::TwoSumHashTable(nums, target);
    std::cout << "TwoSumHashTable Output: ";
    printVector(res2);
    std::cout << "\n\n";
}

int main() {
    // 1. Normal Case
    runTest("Normal Case", {2, 7, 11, 15}, 9);

    // 2. Duplicates: Ensures correct handling of two identical numbers
    runTest("Duplicates Case", {3, 3}, 6);

    // 3. Negative Numbers
    runTest("Negative Numbers", {-1, -2, -3, -4, -5}, -8);

    // 4. Zeroes and Negatives
    runTest("Zeroes and Negatives", {0, 4, 3, 0}, 0);

    // 5. Boundary Condition: Minimum Array Size & Extreme Values
    runTest("Minimum Size Array", {1000000000, -1000000000}, 0);
    
    // 6. Negative Target
    runTest("Negative Target", {2, -7, 11, 15}, -5);

    return 0;
}