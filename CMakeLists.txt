cmake_minimum_required(VERSION 3.20)
project(SortingTest VERSION 1.0 LANGUAGES CXX C)

set(UTILITY_DIR ${CMAKE_SOURCE_DIR}/utility)
add_library(
    utility 
    ${UTILITY_DIR}/random.cpp 
    ${UTILITY_DIR}/array.cpp 
    ${UTILITY_DIR}/timer.cpp
)
target_include_directories(utility PUBLIC ${UTILITY_DIR}/header)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC utility)
