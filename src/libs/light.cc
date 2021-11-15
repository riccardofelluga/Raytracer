#include "light.h"

Light::Light(Vector3 origin, float light_intensity)
    : origin_{origin}, light_intensity_{light_intensity} {}

float Light::At(Vector3 point, Vector3 norm, float diffuse_coeff) {
  Vector3 distance_vector = origin_ - point;
  float light_at_point = norm.dot(distance_vector.normalize());
  return (light_at_point < 0)
             ? 0
             : (diffuse_coeff * light_intensity_ * light_at_point);
}
