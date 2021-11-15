#ifndef LIBS_LIGHT_H_
#define LIBS_LIGHT_H_

#include "libs/vector3.h"

class Light {
 public:
  explicit Light(Vector3 origin, float light_intensity);

  float At(Vector3 point, Vector3 norm, float diffuse_coeff);

 private:
  Vector3 origin_;
  float light_intensity_;
};

#endif  // LIBS_LIGHT_H_
