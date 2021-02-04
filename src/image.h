class Image {
 public:
  Image();
  Image(int rows, int cols) : width_{cols}, height_{rows} {};

  const int& rows() { return height_; }
  const int& cols() { return width_; }

 private:
  int width_;
  int height_;
};
