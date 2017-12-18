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
	Matrix matrix1(1000, 1000, 100);
	Matrix matrix2(1000, 1000, 99);
	Matrix matrix3 = matrix1 * matrix2;
}

