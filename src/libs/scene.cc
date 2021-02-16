#include "scene.h"

Scene::Scene(Camera camera) : camera_{camera} {}

const Camera& Scene::camera() const { return camera_; }

void Scene::AddObject(Object object) { objects_.emplace_back(object); }

bool Scene::Render(Image image) const {
  for (int i = 0; i < image.width(); i++) {
    for (int j = 0; j < image.height(); j++) {
      for (Object o : objects_) {
        Vector3 intersect_normal = o.intersect(camera_.PixelToRay(i, j));
        if (intersect_normal.x() != 0) {
          image.at(i, j) = o.color();
        }
      }
    }
  }
  return image.Write();
}
