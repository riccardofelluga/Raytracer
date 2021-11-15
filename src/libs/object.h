#ifndef LIBS_OBJECT_H_
#define LIBS_OBJECT_H_

#include <math.h>

#include "image.h"
#include "ray.h"
#include "vector3.h"

struct Intersection {
  Vector3 norm;
  Vector3 position;
};
class Object {
 public:
  Object(Vector3 origin, Color color, int radius);

  const Vector3& origin() const;
  const Color& color() const;

  bool intersect(const Ray& ray, Intersection& intersection) const;

 private:
  Vector3 origin_;
  Color color_;
  int radius_;
};

#endif  // LIBS_OBJECT_H_
