cmake_minimum_required(VERSION 3.18..3.21)

project(mymodule)

find_package(GooseFEM REQUIRED)

set(CMAKE_BUILD_TYPE Release)

find_package(pybind11 REQUIRED CONFIG)

find_package(Python REQUIRED COMPONENTS Interpreter Development)

pybind11_add_module(${PROJECT_NAME} main.cpp)

target_compile_definitions(${PROJECT_NAME} PUBLIC VERSION_INFO="1.0")
target_link_libraries(${PROJECT_NAME} PUBLIC GooseFEM pybind11::module)
