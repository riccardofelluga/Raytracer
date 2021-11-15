#include <gtest/gtest.h>

#include "libs/object.h"
#include "libs/ray.h"

TEST(ObjectTest, CreateObjectWithCoordinates) {
  Object object(Vector3(-1.0f, 6.0f, 5.0f), {255, 0, 0}, 1);
  Vector3 object_coordinates = object.origin();
  ASSERT_EQ(object_coordinates.x(), -1.0f);
  ASSERT_EQ(object_coordinates.y(), 6.0f);
  ASSERT_EQ(object_coordinates.z(), 5.0f);
}

TEST(ObjectTest, IntersectWithRay) {
  Object object(Vector3(0, 0, 0), {255, 0, 0}, 1);
  Intersection intersection;
  ASSERT_TRUE(object.intersect(Ray(Vector3(5, -5, 1.5), Vector3(-5, 5, -1.5)),
                               intersection));
}

TEST(ObjectTest, DoesNotIntersectWithRay) {
  Object object(Vector3(0, 0, 0), {255, 0, 0}, 1);
  Intersection intersection;
  ASSERT_FALSE(object.intersect(Ray(Vector3(5, -5, 1.5), Vector3(5, 5, 1.5)),
                                intersection));
}

TEST(ObjectTest, ReturnNormal) {
  Object object(Vector3(0, 0, 0), {255, 0, 0}, 1);
  Intersection intersection;
  object.intersect(Ray(Vector3(5, -5, 1.5), Vector3(-5, 5, -1.5)),
                   intersection);
  ASSERT_NEAR(intersection.norm.x(), 0.69, 0.05);
  ASSERT_NEAR(intersection.norm.y(), -0.69, 0.05);
  ASSERT_NEAR(intersection.norm.z(), 0.21, 0.05);
}
