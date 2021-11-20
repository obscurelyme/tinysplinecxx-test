cmake_minimum_required(VERSION 3.0.0)

project(tinytest VERSION 0.1.0)

find_package(tinyspline CONFIG REQUIRED)

add_executable(tinytest main.cpp)
target_link_libraries(tinytest PRIVATE tinyspline::tinyspline tinysplinecxx::tinysplinecxx)
