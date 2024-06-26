cmake_minimum_required(VERSION 3.26)
project(PSE_project)

set(CMAKE_CXX_STANDARD 14)


set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 17)
# Remove the "-O2" flag if you have problems with the debugger.
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Werror -O2")
set(CMAKE_EXE_LINKER_FLAGS -pthread)

# Set include dir
include_directories(./gtest/include)

# Set Library dir
link_directories(./gtest/lib)

# Set source files for RELEASE target
# Only add cpp files, no h files!
# Only add files with functionality here, no test files!
set(RELEASE_SOURCE_FILES         src/main.cpp
        src/tinystr.cpp
        src/tinyxml.cpp
        src/tinyxmlerror.cpp
        src/tinyxmlparser.cpp
        src/PrintSystemUtils.cpp
        src/Device.cpp
        src/Job.cpp
        src/PrintSystem.cpp
        src/Logger.cpp
)

# Set source files for DEBUG target
# Only add cpp files, no h files!
set(DEBUG_SOURCE_FILES
        src/tinystr.cpp
        src/tinyxml.cpp
        src/tinyxmlerror.cpp
        src/tinyxmlparser.cpp
        src/PrintSystemUtils.cpp
        src/Device.cpp
        src/Job.cpp
        src/PrintSystem.cpp
        src/TEST.cpp
        src/Output.cpp
        src/Logger.cpp)


# Create RELEASE target
add_executable(release_target ${RELEASE_SOURCE_FILES})



# Create DEBUG target
add_executable(debug_target ${DEBUG_SOURCE_FILES})

# Link library
target_link_libraries(debug_target gtest)