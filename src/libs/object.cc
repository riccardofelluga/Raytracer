#include "object.h"

Object::Object(Vector3 origin, Color color, int radius)
    : origin_{origin}, color_{color}, radius_{radius} {}

const Vector3& Object::origin() const { return origin_; }
const Color& Object::color() const { return color_; }

bool Object::intersect(const Ray& ray, Intersection& intersection) const {
  Vector3 distance_from_ray = origin_ - ray.origin();
  float v = distance_from_ray.dot(ray.direction());
  float det =
      radius_ * radius_ - (distance_from_ray.dot(distance_from_ray) - v * v);
  if (det > 0) {
    float d = std::sqrt(det);
    intersection.position = ray.At(v - d);
    intersection.norm = (origin_ - intersection.position).normalize();
    return true;
  }
  return false;
}
