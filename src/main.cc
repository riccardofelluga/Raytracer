#include <iostream>

#include "libs/image.h"
#include "libs/light.h"
#include "libs/object.h"
#include "libs/scene.h"
#include "libs/vector3.h"

int main(int argc, char** argv) {
  std::cout << "HELLO! So this raytracer implements camera, lights, objects, "
               "vectors, images, colors and scenes(with unit tests!! "
               "TDD!)."
            << std::endl;
  Scene scene = Scene(Camera(Vector3(5.0f, -5.0f, 1.5f), Vector3(0, 0, 0),
                             Vector3(0, 0, 1), 30, 36, 800, 1.777f));
  scene.AddObject(Object(Vector3(0, 0, 0), {255, 0, 0}, 1));
  scene.AddObject(Object(Vector3(2, 0, 0), {0, 0, 255}, 1));
  scene.AddObject(Object(Vector3(-2, 0, 0), {0, 255, 0}, 1));
  scene.AddLight(Light(Vector3(3, -3, 3), 1));
  scene.Render(Image("multiple_object_test.ppm", 800, 450));
  return 0;
}
