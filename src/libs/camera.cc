#include "camera.h"

#include <iostream>

Camera::Camera(Vector3 position, Vector3 target_point, Vector3 up,
               int focal_length, int sensor_width, int horizontal_resolution,
               float sensor_aspect_ratio)
    : origin_{position},
      target_point_{target_point},
      up_{up},
      focal_length_{focal_length},
      sensor_width_{sensor_width},
      horizontal_resolution_{horizontal_resolution},
      sensor_aspect_ratio_{sensor_aspect_ratio} {}

Vector3 Camera::origin() const { return origin_; }

Ray Camera::PixelToRay(float pixel_x, float pixel_y) const {
  Vector3 camera_z = (target_point_ - origin_).normalize();
  Vector3 camera_x = camera_z.cross(up_).normalize();
  Vector3 camera_y = camera_z.cross(camera_x);

  int vertical_resolution = horizontal_resolution_ / sensor_aspect_ratio_;
  int sensor_height = sensor_width_ / sensor_aspect_ratio_;

  float u = (pixel_x / (horizontal_resolution_ - 1) - 0.5) * sensor_width_;
  float v = (pixel_y / (vertical_resolution - 1) - 0.5) * sensor_height;

  Vector3 direction =
      (-focal_length_ * camera_z) + (v * camera_y) + (u * camera_x);

  return Ray(origin_, direction.normalize());
}
