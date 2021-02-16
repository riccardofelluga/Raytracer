#include <gtest/gtest.h>

#include "libs/object.h"
#include "libs/ray.h"

TEST(ObjectTest, CreateObjectWithCoordinates) {
  Object object(Vector3(-1.0f, 6.0f, 5.0f), {255, 0, 0});
  Vector3 object_coordinates = object.origin();
  ASSERT_EQ(object_coordinates.x(), -1.0f);
  ASSERT_EQ(object_coordinates.y(), 6.0f);
  ASSERT_EQ(object_coordinates.z(), 5.0f);
}

TEST(ObjectTest, IntersectWithRay) {
  Object object(Vector3(0, 0, 0), {255, 0, 0});
  Vector3 intersect =
      object.intersect(Ray(Vector3(5, -5, 1.5), Vector3(-5, 5, -1.5)));
  ASSERT_TRUE(intersect.x() != 0);
}

TEST(ObjectTest, DoesNotIntersectWithRay) {
  Object object(Vector3(0, 0, 0), {255, 0, 0});
  Vector3 intersect =
      object.intersect(Ray(Vector3(5, -5, 1.5), Vector3(5, 5, 1.5)));
  ASSERT_FALSE(intersect.x() != 0);
}

TEST(ObjectTest, ReturnNormal) {
  Object object(Vector3(0, 0, 0), {255, 0, 0});
  Vector3 normal_at =
      object.intersect(Ray(Vector3(5, -5, 1.5), Vector3(-5, 5, -1.5)));
}
