#include <gtest/gtest.h>

#include "libs/image.h"

class ImageTest : public ::testing::Test {
 protected:
  ImageTest() : image_("test.ppm", 2, 2) {}

  Image image_;
};

TEST_F(ImageTest, WriteImage) {
  ASSERT_TRUE(image_.Write());
  std::ifstream in("test.ppm", std::ios_base::in);
  ASSERT_TRUE(in.is_open());
  in.close();
}

TEST_F(ImageTest, ImageXYWillHavePPMFormatXY) {
  image_.Write();
  std::ifstream in("test.ppm", std::ios_base::in);
  ASSERT_TRUE(in.is_open());
  std::string image_format, image_size, color_value_range;
  std::getline(in, image_format);
  ASSERT_EQ(image_format, "P3");
  std::getline(in, image_size);
  ASSERT_EQ(image_size, "2 2");
  std::getline(in, color_value_range);
  ASSERT_EQ(color_value_range, "255");
  in.close();
}

TEST_F(ImageTest, PutValueAt) {
  image_.at(0, 0) = {255, 255, 255};
  ASSERT_EQ(image_.at(0, 0).x(), 255);
  ASSERT_EQ(image_.at(0, 0).y(), 255);
  ASSERT_EQ(image_.at(0, 0).z(), 255);
}

TEST_F(ImageTest, WritePixelValuesToFile) {
  image_.at(0, 0) = {1, 2, 3};
  image_.Write();
  std::ifstream in("test.ppm", std::ios_base::in);
  std::string line;
  for (int i = 0; i < 3; i++) {
    getline(in, line);
  }
  int red, green, blue;
  in >> red >> green >> blue;
  ASSERT_EQ(red, 1);
  ASSERT_EQ(green, 2);
  ASSERT_EQ(blue, 3);
  in.close();
}

TEST_F(ImageTest, WillWritePixelsInCorrectOrder) {
  image_.at(0, 0) = {1, 2, 3};
  image_.at(1, 0) = {7, 8, 9};
  image_.at(0, 1) = {4, 5, 6};
  image_.at(1, 1) = {10, 11, 12};
  image_.Write();
  std::ifstream in("test.ppm", std::ios_base::in);
  std::string line;
  for (int i = 0; i < 3; i++) {
    getline(in, line);
  }
  int r, g, b;
  in >> r >> g >> b;
  ASSERT_EQ(r, 1);
  ASSERT_EQ(g, 2);
  ASSERT_EQ(b, 3);
  in >> r >> g >> b;
  ASSERT_EQ(r, 7);
  ASSERT_EQ(g, 8);
  ASSERT_EQ(b, 9);
  in >> r >> g >> b;
  ASSERT_EQ(r, 4);
  ASSERT_EQ(g, 5);
  ASSERT_EQ(b, 6);
  in >> r >> g >> b;
  ASSERT_EQ(r, 10);
  ASSERT_EQ(g, 11);
  ASSERT_EQ(b, 12);
  in.close();
}

TEST_F(ImageTest, WriteWithDifferentFilename) {
  image_.Write("filename_test.ppm");
  std::ifstream in("filename_test.ppm", std::ios_base::in);
  ASSERT_TRUE(in.is_open());
  in.close();
}
