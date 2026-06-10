#include <unordered_map>
#include <algorithm>
#include "TwoSum.h"

using namespace std;

// Two Sum using Hash Table - O(n) time, O(n) space
vector<int> TwoSumHashTable(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (map.find(complement) != map.end()) {
            int idx1 = map[complement];
            int idx2 = i;
            return {min(idx1, idx2), max(idx1, idx2)}; 
        }
        map[nums[i]] = i;
    }
    return {};
}

// Two Sum using Array (sorted) - O(n log n) time, O(1) space
vector<int> TwoSumArray(vector<int>& nums, int target) {
    vector<pair<int, int>> numPairs;
    
    for (int i = 0; i < nums.size(); i++) {
        numPairs.push_back({nums[i], i});
    }
    
    sort(numPairs.begin(), numPairs.end());
    
    int left = 0, right = numPairs.size() - 1;
    
    while (left < right) {
        int sum = numPairs[left].first + numPairs[right].first;
        
        if (sum == target) {
            // ✅ 改在這裡！找到答案時，確保順序是由小到大
            return {min(numPairs[left].second, numPairs[right].second), 
                    max(numPairs[left].second, numPairs[right].second)};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    // ✅ 找不到時，乖乖回傳空陣列
    return {};
}