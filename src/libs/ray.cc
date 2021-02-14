#include "ray.h"

Ray::Ray(Vector3 origin, Vector3 direction)
    : origin_{origin}, direction_{direction} {}

Vector3 Ray::origin() const { return origin_; }
Vector3 Ray::direction() const { return direction_; }
