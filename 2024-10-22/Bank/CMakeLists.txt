cmake_minimum_required(VERSION 3.10)
project(Bank)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED True)

add_executable(bank_app main.cpp bank.cpp)

enable_testing()
find_package(GTest REQUIRED)

add_executable(test_bank test_bank.cpp bank.cpp)
target_link_libraries(test_bank PRIVATE GTest::GTest GTest::Main)

add_test(NAME BankTests COMMAND test_bank)