cmake_minimum_required(VERSION 3.26)
project(cpp_histogram)

set(CMAKE_CXX_STANDARD 17)

################################
# Files
################################

set(SOURCE_FILES
        src/main.cpp
        src/Graph.cpp
        src/Node.cpp
)

include_directories(
        includes/
)

################################
# Main Program (Histogram)
################################
add_executable(cpp_graphs ${SOURCE_FILES})
