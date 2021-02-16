#ifndef LIBS_OBJECT_H_
#define LIBS_OBJECT_H_

#include <math.h>

#include "image.h"
#include "ray.h"
#include "vector3.h"

class Object {
 public:
  Object(Vector3 origin, Color color);

  const Vector3& origin() const;
  const Color& color() const;

  Vector3 intersect(const Ray& ray) const;

 private:
  Vector3 origin_;
  Color color_;
};

#endif  // LIBS_OBJECT_H_
