cmake_minimum_required(VERSION 3.0.0)

project(tinytest VERSION 0.1.0)

if (APPLE)
  set(tinysplinecxx_DIR "${CMAKE_BINARY_DIR}/vcpkg_installed/x64-osx/share/tinyspline")
else()
  set(tinysplinecxx_DIR "${CMAKE_BINARY_DIR}/vcpkg_installed/x64-linux/share/tinyspline")
endif()

find_package(tinysplinecxx CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(X11 REQUIRED)

add_executable(tinytest main.cpp)
target_link_libraries(tinytest PRIVATE ${X11_LIBRARIES})
target_link_libraries(tinytest PRIVATE tinysplinecxx::tinysplinecxx)
target_link_libraries(tinytest PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2::SDL2-static)
