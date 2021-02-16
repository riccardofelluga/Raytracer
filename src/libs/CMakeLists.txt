# add the objects
add_library(libs OBJECT 
image.cc
vector3.cc
scene.cc
object.cc
camera.cc
ray.cc)

# link libraries together to use them from one another lib.
# target_link_libraries(utils another_lib)