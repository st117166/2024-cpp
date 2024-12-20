cmake_minimum_required(VERSION 3.10)
project(TextEditor)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED True)

add_executable(text_editor_app main.cpp text_editor.cpp)

enable_testing()
find_package(GTest REQUIRED)

add_executable(test_text_editor test_text_editor.cpp text_editor.cpp)
target_link_libraries(test_text_editor PRIVATE GTest::GTest GTest::Main)

add_test(NAME TextEditorTests COMMAND test_text_editor)
