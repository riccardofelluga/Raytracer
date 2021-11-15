#include <gtest/gtest.h>

#include "libs/camera.h"
#include "libs/object.h"
#include "libs/scene.h"

class SceneTest : public ::testing::Test {
 protected:
  SceneTest()
      : scene_(Camera(Vector3(5, -4, 3.0f),
                      Vector3(0, 0, 0),  // 7.0f, -4.0f, -1.0f
                      Vector3(0, 0, -1), 30, 36, 800, 1.777f)) {}

  Scene scene_;
};

TEST_F(SceneTest, AddObjectToScene) {
  scene_.AddObject(Object(Vector3(0, 0, 0), {255, 0, 0}, 1));
}

TEST_F(SceneTest, WriteRenderedSceneGivenImage) {
  scene_.Render(Image("render_test.ppm", 2, 2));
  std::ifstream in("render_test.ppm");
  ASSERT_TRUE(in.is_open());
  in.close();
}

TEST_F(SceneTest, RenderDemoScene) {
  scene_.AddObject(Object(Vector3(0, 0, 0), {255, 0, 0}, 1));
  scene_.AddLight(Light(Vector3(3, 3, 3), 0.5f));
  scene_.Render(Image("render_test.ppm", 800, 450));
  std::ifstream in("render_test.ppm");
  ASSERT_TRUE(in.is_open());
  in.close();
}

TEST_F(SceneTest, RenderWithMultipleObject) {
  scene_.AddObject(Object(Vector3(0, 0, 0), {255, 0, 0}, 1));
  scene_.AddObject(Object(Vector3(2, 0, 0), {0, 0, 255}, 1));
  scene_.AddObject(Object(Vector3(3, -3, 0), {0, 255, 0}, 1));
  scene_.AddObject(Object(Vector3(0, 0, 200), {255, 255, 0}, -220));
  scene_.AddLight(Light(Vector3(5, -4, 3), 0.5f));
  scene_.Render(Image("multiple_object_test.ppm", 800, 450));
}
