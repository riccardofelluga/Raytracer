#include "scene.h"

Scene::Scene(Camera camera) : camera_{camera} {}

const Camera& Scene::camera() const { return camera_; }

void Scene::AddObject(Object object) { objects_.emplace_back(object); }

void Scene::AddLight(Light light) { lights_.emplace_back(light); }

bool Scene::Render(Image image) const {
  for (int i = 0; i < image.width(); i++) {
    for (int j = 0; j < image.height(); j++) {
      float closest_distance = std::numeric_limits<float>::infinity();
      Intersection closest_intersection, intersection_record;
      Color color_intensity = {0, 0, 0};
      bool pixel_intersected = false;
      for (Object o : objects_) {
        pixel_intersected =
            o.intersect(camera_.PixelToRay(i, j), intersection_record);
        if (pixel_intersected) {
          float intersection_distance =
              (camera_.origin() - intersection_record.position).length();
          if (intersection_distance < closest_distance) {
            closest_distance = intersection_distance;
            color_intensity = o.color();
          }
        }
      }
      for (Light l : lights_) {
        color_intensity = color_intensity * l.At(intersection_record.position,
                                                 intersection_record.norm, 0.8);
      }
      image.at(i, j) = color_intensity;
    }
  }
  return image.Write();
}
