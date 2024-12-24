cmake_minimum_required(VERSION 3.10)
project(Dataset)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED True)

add_executable(dataset_app main.cpp dataset.cpp)

enable_testing()
find_package(GTest REQUIRED)

add_executable(test_dataset test_dataset.cpp dataset.cpp)
target_link_libraries(test_dataset PRIVATE GTest::GTest GTest::Main)

add_test(NAME DatasetTests COMMAND test_dataset)