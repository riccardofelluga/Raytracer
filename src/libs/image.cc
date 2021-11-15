#include "image.h"

Image::Image(const std::string file_name, int width, int height)
    : width_{width},
      height_{height},
      data_(width * height),
      file_name_{file_name} {}

int Image::width() const { return width_; }
int Image::height() const { return height_; }

bool Image::Write() const { return Write(file_name_); }

bool Image::Write(const std::string& file_name) const {
  std::ofstream out_file(file_name);
  if (!out_file.is_open()) {
    return false;
  }

  out_file << "P3\n" << width_ << " " << height_ << "\n255\n";

  for (Color pixel_value : data_) {
    out_file << (int)pixel_value.x() << " " << (int)pixel_value.y() << " "
             << (int)pixel_value.z() << "\n";
  }

  out_file.close();
  return true;
}

Color& Image::at(int x, int y) { return data_[width_ * y + x]; }
