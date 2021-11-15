#include <gtest/gtest.h>

#include "libs/light.h"

TEST(LightTest, GetIntensityAt) {
  Light l({0, 0, 0}, 1);
  float light_at = l.At({5, -5, 1.5}, {2, -4, 8}, 1);
  ASSERT_NEAR(light_at, 0.11, 0.05);
}
