#ifndef LIBS_VECTOR3_H_
#define LIBS_VECTOR3_H_

#include <cmath>
#include <iostream>

class Vector3 {
 public:
  Vector3(float x, float y, float z);

  float x() const;
  float y() const;
  float z() const;

  Vector3 operator-() const;
  Vector3 operator*(const Vector3& vector) const;
  Vector3 operator+(const Vector3& vector) const;

  Vector3 cross(const Vector3& vector) const;
  Vector3 normalize() const;

  float length() const;

 private:
  float x_;
  float y_;
  float z_;
};

Vector3 operator*(const Vector3& vector, const float scalar);
Vector3 operator*(const float scalar, const Vector3& vector);

Vector3 operator/(const Vector3& vector, const float scalar);

Vector3 operator-(const Vector3& a, const Vector3& b);

#endif  // LIBS_VECTOR3_H_
