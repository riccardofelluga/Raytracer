#include <gtest/gtest.h>

#include "libs/vector3.h"

class Vector3Test : public ::testing::Test {
 protected:
  Vector3Test() : vector_(0.0f, -1.0f, 33.0f) {}

  Vector3 vector_;
};

TEST_F(Vector3Test, WillReturnItself_AfterMultWithUnitaryVec) {
  Vector3 mult_vector = vector_ * Vector3(1.0f, 1.0f, 1.0f);
  ASSERT_EQ(mult_vector.x(), 0.0f);
  ASSERT_EQ(mult_vector.y(), -1.0f);
  ASSERT_EQ(mult_vector.z(), 33.0f);
}

TEST_F(Vector3Test, WillInvertSign) {
  Vector3 inverted = -vector_;
  ASSERT_EQ(inverted.x(), 0.0f);
  ASSERT_EQ(inverted.y(), +1.0f);
  ASSERT_EQ(inverted.z(), -33.0f);
}

TEST_F(Vector3Test, WillReturnZeroVector_AfterBy0Mult) {
  Vector3 zero_mult = vector_ * 0;
  ASSERT_EQ(zero_mult.x(), 0.0f);
  ASSERT_EQ(zero_mult.y(), 0.0f);
  ASSERT_EQ(zero_mult.z(), 0.0f);
}

TEST_F(Vector3Test, WillReturnItself_AfterBy1Mult) {
  Vector3 one_mult = vector_ * 1;
  ASSERT_EQ(one_mult.x(), 0.0f);
  ASSERT_EQ(one_mult.y(), -1.0f);
  ASSERT_EQ(one_mult.z(), 33.0f);
}

TEST_F(Vector3Test, WillReturnZ_AfterByNMult) {
  Vector3 ten_mult = vector_ * 10;
  ASSERT_EQ(ten_mult.x(), 0.0f);
  ASSERT_EQ(ten_mult.y(), -10.0f);
  ASSERT_EQ(ten_mult.z(), 330.0f);
}

TEST_F(Vector3Test, LeftHandScalarMult_IsTheSameAsRightHand) {
  Vector3 zero_mult = 0 * vector_;
  ASSERT_EQ(zero_mult.x(), 0.0f);
  ASSERT_EQ(zero_mult.y(), 0.0f);
  ASSERT_EQ(zero_mult.z(), 0.0f);

  Vector3 one_mult = 1 * vector_;
  ASSERT_EQ(one_mult.x(), 0.0f);
  ASSERT_EQ(one_mult.y(), -1.0f);
  ASSERT_EQ(one_mult.z(), 33.0f);

  Vector3 ten_mult = 10 * vector_;
  ASSERT_EQ(ten_mult.x(), 0.0f);
  ASSERT_EQ(ten_mult.y(), -10.0f);
  ASSERT_EQ(ten_mult.z(), 330.0f);
}

TEST_F(Vector3Test, CrossProduct_Unitary) {
  Vector3 a_vector(1, 0, 0);
  Vector3 b_vector(0, 1, 0);
  Vector3 corss_prod = a_vector.cross(b_vector);
  ASSERT_EQ(corss_prod.x(), 0);
  ASSERT_EQ(corss_prod.y(), 0);
  ASSERT_EQ(corss_prod.z(), 1);
}

TEST_F(Vector3Test, CrossProduct_General) {
  Vector3 a_vector(1, 2, 3);
  Vector3 b_vector(4, 5, 6);
  Vector3 corss_prod = a_vector.cross(b_vector);
  ASSERT_EQ(corss_prod.x(), -3);
  ASSERT_EQ(corss_prod.y(), 6);
  ASSERT_EQ(corss_prod.z(), -3);
}

TEST_F(Vector3Test, SumOfTwoVectors) {
  Vector3 sum = vector_ + Vector3(1, 1, 1);
  ASSERT_EQ(sum.x(), 1);
  ASSERT_EQ(sum.y(), 0);
  ASSERT_EQ(sum.z(), 34);
}

TEST_F(Vector3Test, VectorScalarDivision) {
  Vector3 div = vector_ / 2;
  ASSERT_EQ(div.x(), 0);
  ASSERT_EQ(div.y(), -0.5f);
  ASSERT_EQ(div.z(), 16.5f);
}

TEST_F(Vector3Test, VectorLenght_Unitary) {
  Vector3 unitary_x(1, 0, 0);
  Vector3 unitary_y(0, 1, 0);
  Vector3 unitary_z(0, 0, 1);
  ASSERT_EQ(unitary_x.length(), 1);
  ASSERT_EQ(unitary_y.length(), 1);
  ASSERT_EQ(unitary_z.length(), 1);
}

TEST_F(Vector3Test, VectorLenght_General) {
  Vector3 sqaureable_vec(2, 2, 1);
  ASSERT_EQ(sqaureable_vec.length(), 3);
}

TEST_F(Vector3Test, NormalizeVector_Unitary) {
  Vector3 uintary(1, 0, 0);
  Vector3 norm = uintary.normalize();
  ASSERT_EQ(norm.length(), 1);
}

TEST_F(Vector3Test, NormalizeVector_General) {
  Vector3 norm = vector_.normalize();
  ASSERT_EQ(norm.length(), 1);
}

TEST_F(Vector3Test, SubtractionByVector) {
  Vector3 sub = vector_ - Vector3(1, 1, 1);
  ASSERT_EQ(sub.x(), -1);
  ASSERT_EQ(sub.y(), -2);
  ASSERT_EQ(sub.z(), 32);
}
