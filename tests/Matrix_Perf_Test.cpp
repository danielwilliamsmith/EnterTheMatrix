/*
 * Matrix_Perf_Test.cpp
 *
 *  Created on: Dec 18, 2017
 *      Author: dws
 */

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../src/Matrix.hpp"

// Multiplication of large matrices.
TEST(MatrixPerfTest, BigMultiply) {
	Matrix matrix1(3000, 3000, 1000);
	Matrix matrix2(3000, 3000, 9900);
	Matrix matrix3 = matrix1 * matrix2;
}

TEST(MatrixPerfTest, BiggerMultiply) {
	Matrix matrix1(5000, 5000, 1000);
	Matrix matrix2(5000, 5000, 9900);
	Matrix matrix3 = matrix1 * matrix2;
}

TEST(MatrixPerfTest, BiggestMultiply) {
	Matrix matrix1(7000, 7000, 1000);
	Matrix matrix2(7000, 7000, 9900);
	Matrix matrix3 = matrix1 * matrix2;
}

// Addition of large matrices.
TEST(MatrixPerfTest, BigAdd) {
	Matrix matrix1(5000, 5000, 1000);
	Matrix matrix2(5000, 5000, 9900);
	Matrix matrix3 = matrix1 + matrix2;
}

// Subtraction of large matrices.
TEST(MatrixPerfTest, BigSubtract) {
	Matrix matrix1(5000, 5000, 1000);
	Matrix matrix2(5000, 5000, 9900);
	Matrix matrix3 = matrix1 - matrix2;
}
