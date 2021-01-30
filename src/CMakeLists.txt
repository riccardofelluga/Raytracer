# uncomment to add packages
# find_package(pkg_name REQUIRED)
# include_directories(${pkg_name_INCLUDE_DIRS})

link_directories(/usr/local/lib)

# add the library subdirectory
add_subdirectory(libs)

# add the main executable
add_executable(main main.cpp)

#tell the linker what to link
target_link_libraries(main utils)# ${pkg_name_LIBRARIES})

