project(cpp_boilerplate) #mandatory
cmake_minimum_required(VERSION 3.1) #mandatory
set(CMAKE_CXX_STANDARD 11) #use c++11
# Set build type if not set.
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

#set to see all warnings
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
#keep debug info in the binary
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
#set optimization level 0, 1, 2, 3 
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

#tell cmake where to put output binaries
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#tell cmake where to put output libraries binaries
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# thell where to look for .h files 
include_directories(${PROJECT_SOURCE_DIR}/src)

# Outsource the actual processing to folders. separation of concerns
add_subdirectory(src)

enable_testing() #mandatory in the top most folder 
# Outsorce test configuration in the test folder
add_subdirectory(tests)


