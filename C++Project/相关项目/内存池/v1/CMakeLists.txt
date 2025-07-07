cmake_minimum_required(VERSION 3.31)
project(memoryPool)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Include directories
include_directories(include)

file(GLOB SRC_FILES "v1/*.cpp")
file(GLOB TEST_FILES "v1/*.cpp")
add_executable(memoryPool MemoryPool_V1.cpp MemoryPool_V1.h test.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE -g -pthread)

# Link libraries
target_link_libraries(${PROJECT_NAME} pthread)