// src/main.cpp
#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include "TwoSum.h"

using namespace std;
namespace fs = std::filesystem;

// 專門處理單一測資檔案的函式
bool runTestFile(const string& filepath) {
    ifstream infile(filepath);
    if (!infile.is_open()) {
        cerr << "  [Error] Cannot open file: " << filepath << endl;
        return false;
    }

    int target, numSize;
    int testCaseNum = 1;
    bool allPassed = true;

    // 只要還讀得到 target 和陣列大小，就繼續迴圈
    while (infile >> target >> numSize) {
        vector<int> nums(numSize);
        for (int i = 0; i < numSize; i++) {
            infile >> nums[i];
        }

        int expectedSize;
        infile >> expectedSize;
        vector<int> expected(expectedSize);
        for (int i = 0; i < expectedSize; i++) {
            infile >> expected[i];
        }

        // 執行你的兩個演算法
        vector<int> resultHash = TwoSumHashTable(nums, target);
        vector<int> resultArray = TwoSumArray(nums, target);

        // 驗證結果
        if (resultHash != expected) {
            cerr << "    ❌ Test Case " << testCaseNum << " (Hash Table) Failed!" << endl;
            allPassed = false;
        } else if (resultArray != expected) {
            cerr << "    ❌ Test Case " << testCaseNum << " (Array Sort) Failed!" << endl;
            allPassed = false;
        }

        testCaseNum++;
    }

    infile.close();
    return allPassed;
}

int main() {
    cout << "=== Starting Data-Driven Testing via main.cpp ===" << endl;

    string testDir = "test_data";
    bool allFilesPassed = true;

    // 檢查資料夾是否存在
    if (!fs::exists(testDir) || !fs::is_directory(testDir)) {
        cerr << "Cannot find test_data directory!" << endl;
        return 1;
    }

    // 走訪 test_data 資料夾內的所有檔案
    for (const auto& entry : fs::directory_iterator(testDir)) {
        // 只處理副檔名為 .txt 的檔案
        if (entry.path().extension() == ".txt") {
            string filepath = entry.path().string();
            string filename = entry.path().filename().string();
            
            cout << "\n📂 Testing file: " << filename << endl;
            
            // 執行該檔案的測試
            bool passed = runTestFile(filepath);
            
            if (passed) {
                cout << "  ✅ All test cases passed in " << filename << "!" << endl;
            } else {
                cout << "  ❌ Some test cases failed in " << filename << "!" << endl;
                allFilesPassed = false;
            }
        }
    }

    cout << "\n===================================" << endl;
    if (allFilesPassed) {
        cout << "🎉 Congratulations! All test files passed successfully!" << endl;
    } else {
        cerr << "⚠️ Test Failed: Some test cases did not pass the check." << endl;
    }

    return 0;
}