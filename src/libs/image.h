#ifndef LIBS_IMAGE_H_
#define LIBS_IMAGE_H_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "vector3.h"

struct Color {
  int r;
  int g;
  int b;
};

class Image {
 public:
  Image(const std::string file_name, int width, int height);

  Color& at(int x, int y);

  int width() const;
  int height() const;

  bool Write() const;
  bool Write(const std::string& file_name) const;

 private:
  int width_;
  int height_;
  std::vector<Color> data_;
  std::string file_name_;
};

#endif  // LIBS_IMAGE_H_
