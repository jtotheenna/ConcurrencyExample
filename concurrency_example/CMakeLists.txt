cmake_minimum_required(VERSION 3.16)
project(ConcurrencyExample)

set(CMAKE_CXX_STANDARD 11)

add_executable(ConcurrencyExample concurrency_example.cpp
        concurrency_example.cpp
)

# Link the pthread library for threading support
target_link_libraries(ConcurrencyExample pthread)
