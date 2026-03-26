#include <vector>
#include <unordered_map>

using namespace std;

// Two Sum using Hash Table - O(n) time, O(n) space
vector<int> TwoSumHashTable(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        
        if (map.find(complement) != map.end()) {
            return {map[complement], i};
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
            return {numPairs[left].second, numPairs[right].second};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    return {};
}