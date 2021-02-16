#include <gtest/gtest.h>

#include "libs/camera.h"

class CameraTest : public ::testing::Test {
 protected:
  CameraTest()
      : camera_(Vector3(5.0f, -5.0f, 1.5f), Vector3(0, 0, 0), Vector3(0, 0, 1),
                50, 36, 1920, 1.777f) {}
  Camera camera_;
};

TEST_F(CameraTest, RayHasSameOriginAsCamera) {
  Ray new_ray = camera_.PixelToRay(0, 0);
  ASSERT_EQ(new_ray.origin().x(), 5.0f);
  ASSERT_EQ(new_ray.origin().y(), -5.0f);
  ASSERT_EQ(new_ray.origin().z(), 1.5f);
}

TEST_F(CameraTest, RayDirection) {
  Ray new_ray = camera_.PixelToRay(0, 0);
  ASSERT_NEAR(new_ray.direction().x(), 0.38f, 0.05);
  ASSERT_NEAR(new_ray.direction().y(), -0.85f, 0.05);
  ASSERT_NEAR(new_ray.direction().z(), 0.37f, 0.05);
}

TEST_F(CameraTest, RayDirectionIsNormalized) {
  Ray new_ray = camera_.PixelToRay(0, 0);
  ASSERT_NEAR(new_ray.direction().length(), 1, 0.01);
}

TEST_F(CameraTest, RayCenterPixel) {
  Ray center_ray = camera_.PixelToRay(960, 540);
  ASSERT_NEAR(center_ray.direction().x(), 0.69f, 0.05);
  ASSERT_NEAR(center_ray.direction().y(), -0.69f, 0.05);
  ASSERT_NEAR(center_ray.direction().z(), 0.21f, 0.05);
}

TEST_F(CameraTest, RayLastPixel) {
  Ray center_ray = camera_.PixelToRay(1920, 1080);
  ASSERT_NEAR(center_ray.direction().x(), 0.90f, 0.05);
  ASSERT_NEAR(center_ray.direction().y(), -0.43f, 0.05);
  ASSERT_NEAR(center_ray.direction().z(), 0.01f, 0.05);
}
