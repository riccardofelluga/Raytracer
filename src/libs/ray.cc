#include "ray.h"

Ray::Ray(Vector3 origin, Vector3 direction)
    : origin_{origin}, direction_{direction} {}

Vector3 Ray::origin() const { return origin_; }
Vector3 Ray::direction() const { return direction_; }
Vector3 Ray::At(float t) const { return origin_ + t * direction_; }
