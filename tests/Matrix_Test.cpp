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

class MatrixTest : public ::testing::Test {
	protected:
		Matrix * matrixThreeByFour;

		virtual void SetUp() {
			matrixThreeByFour = new Matrix(3, 4);

			int row1Arr[] = {1, 2, 3, 4};
			int row2Arr[] = {5, 6, 7, 8};
			int row3Arr[] = {9, 10, 11, 12};
			std::vector<int> row1Vect(row1Arr, row1Arr + (sizeof(row1Arr)/sizeof(row1Arr[0])));
			std::vector<int> row2Vect(row2Arr, row2Arr + (sizeof(row2Arr)/sizeof(row2Arr[0])));
			std::vector<int> row3Vect(row3Arr, row3Arr + (sizeof(row3Arr)/sizeof(row3Arr[0])));

			matrixThreeByFour->addRow(row1Vect);
			matrixThreeByFour->addRow(row2Vect);
			matrixThreeByFour->addRow(row3Vect);
		}

		virtual void TearDown() {
			delete matrixThreeByFour;
		}
};

TEST_F(MatrixTest, AddRowsValid){
	EXPECT_THAT((*matrixThreeByFour)[0], ElementsAre(1, 2, 3, 4));
	EXPECT_THAT((*matrixThreeByFour)[1], ElementsAre(5, 6, 7, 8));
	EXPECT_THAT((*matrixThreeByFour)[2], ElementsAre(9, 10, 11, 12));
}


