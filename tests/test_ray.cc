#include <gtest/gtest.h>

#include "libs/ray.h"

class RayTest : public ::testing::Test {
 protected:
  RayTest() : ray_(Vector3(5.0f, 99.0f, -1.0f), Vector3(7.0f, 8.9f, 0.0f)) {}

  Ray ray_;
};

TEST_F(RayTest, RayWithOrigin) {
  Vector3 ray_origin = ray_.origin();
  ASSERT_EQ(ray_origin.x(), 5.0f);
  ASSERT_EQ(ray_origin.y(), 99.0f);
  ASSERT_EQ(ray_origin.z(), -1.0f);
}

TEST_F(RayTest, RayWithDirection) {
  Vector3 ray_direction = ray_.direction();
  ASSERT_EQ(ray_direction.x(), 7.0f);
  ASSERT_EQ(ray_direction.y(), 8.9f);
  ASSERT_EQ(ray_direction.z(), 0.0f);
}

TEST_F(RayTest, GetRayAtT) {
  Vector3 ray_at = ray_.At(1.0f);
  ASSERT_EQ(ray_at.x(), 12.0f);
  ASSERT_EQ(ray_at.y(), 107.9f);
  ASSERT_EQ(ray_at.z(), -1.0f);
}
