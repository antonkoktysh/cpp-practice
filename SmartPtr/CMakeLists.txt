cmake_minimum_required(VERSION 3.14)
project(shared_ptr)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "ASAN")
  add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
  add_link_options(-fsanitize=address)
endif()
find_package(Catch2 REQUIRED COMPONENTS Catch2WithMain)

add_executable(tests test.cpp smart_ptr.h)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
