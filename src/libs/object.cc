#include "object.h"

Object::Object(Vector3 origin, Color color) : origin_{origin}, color_{color} {}

const Vector3& Object::origin() const { return origin_; }
const Color& Object::color() const { return color_; }

Vector3 Object::intersect(const Ray& ray) const {
  float radius = 1;
  Vector3 distance = ray.origin() - origin_;
  float a = ray.direction().dot(ray.direction());
  float b = 2 * distance.dot(ray.direction());
  float c = distance.dot(distance) - radius * radius;
  float det = (b * b - 4 * a * c);
  if (det > 0) {
    float t = (-b - std::sqrt(det)) / (2 * a);
    Vector3 norm = (ray.origin() + t * ray.direction()) - origin_;
    Vector3 norm_d = norm / norm.length();
    return norm_d;
  }
  return {0, 0, 0};
}
