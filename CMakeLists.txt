cmake_minimum_required(VERSION 3.14) #mandatory
project(raytracer) #mandatory
set(CMAKE_CXX_STANDARD 20) #use c++11
# Set build type if not set.
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

#set to see all warnings and if windows set exception handling mode to sc [https://docs.microsoft.com/en-us/cpp/build/reference/eh-exception-handling-model?view=msvc-170]
if(MSVC)
    set(CMAKE_CXX_FLAGS "-EHsc")
else()
    set(CMAKE_CXX_FLAGS "-Wall -Wextra")
    #keep debug info in the binary
    set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
endif()

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
 
# Outsorce test configuration in the test folder
add_subdirectory(tests)


