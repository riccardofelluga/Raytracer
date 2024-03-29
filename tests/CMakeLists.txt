## If you are on Ubuntu, install gtest sources with:
##
##     sudo apt install libgtest-dev
##
# add_subdirectory(/usr/src/gtest
                #  ${PROJECT_BINARY_DIR}/gtest)
## If you are not on Ubuntu, you will need to download the source of the
## googletest framework manually and provide the folder to which you have
## - installed it.
include(FetchContent)

FetchContent_Declare(
    googletest 
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
if(MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif() #MSVC

FetchContent_MakeAvailable(googletest)

include_directories(/usr/local/include)

# link the libraries to test
link_directories(/usr/local/lib)

# Include testing cmake package.
include(CTest)
enable_testing()

# Set binary name for convenience.
set(TEST_BINARY ${PROJECT_NAME}_test)

include(GoogleTest)

# This is an executable that runs the tests.
add_executable(${TEST_BINARY} 
test_vector3.cc
test_image.cc
test_scene.cc
test_object.cc
test_camera.cc
test_ray.cc
test_light.cc)

# Link the executable to needed libraries.
target_link_libraries(${TEST_BINARY} 
libs 
gtest gtest_main # GTest libraries
)

gtest_discover_tests(${TEST_BINARY})

# Add gtest to be able to run ctest
add_test(
    NAME ${TEST_BINARY}
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/${TEST_BINARY}
    )
