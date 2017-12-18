/*
 * Matrix_Perf_Test.cpp
 *
 *  Created on: Dec 18, 2017
 *      Author: dws
 */

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../src/Matrix.hpp"

// Try to add a row with too many columns.
TEST(MatrixPerfTest, BigMultiply) {
	Matrix matrix1(5000, 5000, 1000);
	Matrix matrix2(5000, 5000, 9900);
	Matrix matrix3 = matrix1 * matrix2;
}

// Try to add a row with too many columns.
TEST(MatrixPerfTest, BigAdd) {
	Matrix matrix1(5000, 5000, 1000);
	Matrix matrix2(5000, 5000, 9900);
	Matrix matrix3 = matrix1 + matrix2;
}
