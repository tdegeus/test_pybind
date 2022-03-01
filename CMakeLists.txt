cmake_minimum_required(VERSION 3.18..3.21)

project("_mymodule")

find_package(xtensor REQUIRED)

set(CMAKE_BUILD_TYPE Release)

find_package(pybind11 REQUIRED CONFIG)
find_package(NumPy REQUIRED)

pybind11_add_module(${PROJECT_NAME} main.cpp)

target_compile_definitions(${PROJECT_NAME} PUBLIC VERSION_INFO="1.0")
target_include_directories(${PROJECT_NAME} PUBLIC ${NumPy_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC xtensor)

if(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES INSTALL_RPATH "@loader_path/${CMAKE_INSTALL_LIBDIR}")
else()
    set_target_properties(${PROJECT_NAME} PROPERTIES INSTALL_RPATH "$ORIGIN/${CMAKE_INSTALL_LIBDIR}")
endif()
install(TARGETS ${PROJECT_NAME} DESTINATION .)
