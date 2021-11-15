#ifndef LIBS_CAMERA_H_
#define LIBS_CAMERA_H_

#include "ray.h"

class Camera {
 public:
  Camera(Vector3 position, Vector3 target_point, Vector3 up, int focal_length,
         int sensor_width, int horizontal_resolution,
         float sensor_aspect_ratio);

  Ray PixelToRay(float pixel_x, float pixel_y) const;

  Vector3 origin() const;

 private:
  Vector3 origin_;
  Vector3 target_point_;
  Vector3 up_;
  int focal_length_;
  int sensor_width_;
  int horizontal_resolution_;
  float sensor_aspect_ratio_;
};

#endif  // LIBS_CAMERA_H_
