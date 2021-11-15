#ifndef LIBS_SCENE_H_
#define LIBS_SCENE_H_

#include <vector>

#include "camera.h"
#include "image.h"
#include "light.h"
#include "object.h"

class Scene {
 public:
  explicit Scene(Camera camera);

  const Camera& camera() const;

  void AddObject(Object object);

  void AddLight(Light light);

  bool Render(Image image) const;

 private:
  Camera camera_;
  std::vector<Object> objects_;
  std::vector<Light> lights_;
};

#endif  // LIBS_SCENE_H_
