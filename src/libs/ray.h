#ifndef LIBS_RAY_H_
#define LIBS_RAY_H_

#include "vector3.h"

class Ray {
 public:
  Ray(Vector3 origin, Vector3 direction);

  Vector3 origin() const;
  Vector3 direction() const;
  Vector3 At(float t) const;

 private:
  Vector3 origin_;
  Vector3 direction_;
};

#endif  // LIBS_RAY_H_
