/*
 * Matrix_Test.cpp
 *
 *  Created on: Dec 14, 2017
 *      Author: dws
 */

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../src/Matrix.hpp"

#include <vector>

using ::testing::ElementsAre;
using ::testing::ContainerEq;

TEST(MatrixTest, AddRowsValid){
	Matrix myMatrix(3, 4);

	int row1Arr[] = {1, 2, 3, 4};
	int row2Arr[] = {5, 6, 7, 8};
	int row3Arr[] = {9, 10, 11, 12};
	std::vector<int> row1Vect(row1Arr, row1Arr + (sizeof(row1Arr)/sizeof(row1Arr[0])));
	std::vector<int> row2Vect(row2Arr, row2Arr + (sizeof(row2Arr)/sizeof(row2Arr[0])));
	std::vector<int> row3Vect(row3Arr, row3Arr + (sizeof(row3Arr)/sizeof(row3Arr[0])));

	myMatrix.addRow(row1Vect);
	myMatrix.addRow(row2Vect);
	myMatrix.addRow(row3Vect);


	EXPECT_THAT(myMatrix[0], ElementsAre(1, 2, 3, 4));
}


