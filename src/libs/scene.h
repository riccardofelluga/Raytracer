#ifndef LIBS_SCENE_H_
#define LIBS_SCENE_H_

#include <vector>

#include "camera.h"
#include "image.h"
#include "object.h"

class Scene {
 public:
  explicit Scene(Camera camera);

  const Camera& camera() const;

  void AddObject(Object object);

  bool Render(Image image) const;

 private:
  Camera camera_;
  std::vector<Object> objects_;
};

#endif  // LIBS_SCENE_H_
