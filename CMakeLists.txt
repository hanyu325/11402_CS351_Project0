# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# 專案名稱
project(TwoSumProject)

# 設定使用 C++17 標準
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 1. 編譯你的主程式 (現在 main.cpp 已經包含了測試邏輯)
add_executable(main_app src/main.cpp src/TwoSum.cpp)

# (把下面這些原本關於 test_app 的設定刪除，因為檔案已經不在了)
# enable_testing()
# add_executable(test_app src/test_TwoSum.cpp src/TwoSum.cpp)
# add_test(NAME TwoSumAllTests COMMAND test_app)

# 2. 將整個 test_data 資料夾複製到執行檔所在的資料夾 (保留這段！)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test_data 
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})