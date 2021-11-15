#include "vector3.h"

Vector3::Vector3() : x_{0}, y_{0}, z_{0} {}
Vector3::Vector3(float x, float y, float z) : x_{x}, y_{y}, z_{z} {}

float Vector3::x() const { return x_; }
float Vector3::y() const { return y_; }
float Vector3::z() const { return z_; }

Vector3 Vector3::operator-() const { return Vector3(-x_, -y_, -z_); }
Vector3 Vector3::operator*(const Vector3& vector) const {
  return Vector3(x_ * vector.x(), y_ * vector.y(), z_ * vector.z());
}
Vector3 Vector3::operator+(const Vector3& vector) const {
  return Vector3(x_ + vector.x(), y_ + vector.y(), z_ + vector.z());
}

Vector3 Vector3::cross(const Vector3& vector) const {
  return Vector3(y_ * vector.z() - z_ * vector.y(),
                 z_ * vector.x() - x_ * vector.z(),
                 x_ * vector.y() - y_ * vector.x());
}

float Vector3::dot(const Vector3& vector) const {
  return x_ * vector.x() + y_ * vector.y() + z_ * vector.z();
}

Vector3 Vector3::normalize() const { return *this / this->length(); }

float Vector3::length() const { return std::sqrt(this->dot(*this)); }

Vector3 operator*(const Vector3& vector, const float scalar) {
  return Vector3(vector.x() * scalar, vector.y() * scalar, vector.z() * scalar);
}

Vector3 operator*(const float scalar, const Vector3& vector) {
  return vector * scalar;
}

Vector3 operator/(const Vector3& vector, const float scalar) {
  return Vector3(vector.x() / scalar, vector.y() / scalar, vector.z() / scalar);
}

Vector3 operator-(const Vector3& a, const Vector3& b) {
  return Vector3(a.x() - b.x(), a.y() - b.y(), a.z() - b.z());
}
