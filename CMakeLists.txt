cmake_minimum_required(VERSION 3.0.0)

project(tinytest VERSION 0.1.0)

set(tinysplinecxx_DIR "${CMAKE_BINARY_DIR}/vcpkg_installed/x64-osx/share/tinyspline")
find_package(tinysplinecxx CONFIG REQUIRED)

add_executable(tinytest main.cpp)
target_link_libraries(tinytest PRIVATE tinysplinecxx::tinysplinecxx)
