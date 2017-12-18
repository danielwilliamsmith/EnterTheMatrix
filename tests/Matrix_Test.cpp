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
using ::testing::Eq;
using ::testing::ContainerEq;

class MatrixTest : public ::testing::Test {
	protected:
		Matrix* matrixThreeByFour;
		Matrix* matrixFourByTwo;
		Matrix* matrixFourByTwo2;

		virtual void SetUp() {

			// Create a 3x4 matrix.
			int row1Arr[] = {1, 2, 3, 4};
			int row2Arr[] = {5, 6, 7, 8};
			int row3Arr[] = {9, 10, 11, 12};
			std::vector<int> row1Vect(row1Arr, row1Arr + (sizeof(row1Arr)/sizeof(row1Arr[0])));
			std::vector<int> row2Vect(row2Arr, row2Arr + (sizeof(row2Arr)/sizeof(row2Arr[0])));
			std::vector<int> row3Vect(row3Arr, row3Arr + (sizeof(row3Arr)/sizeof(row3Arr[0])));

			matrixThreeByFour = new Matrix(3, 4);
			matrixThreeByFour->addRow(row1Vect);
			matrixThreeByFour->addRow(row2Vect);
			matrixThreeByFour->addRow(row3Vect);

			// Create a 4x2 matrix.
			int row4Arr[] = {1, 2};
			int row5Arr[] = {3, 4};
			int row6Arr[] = {5, 6};
			int row7Arr[] = {7, 8};
			std::vector<int> row4Vect(row4Arr, row4Arr + (sizeof(row4Arr)/sizeof(row4Arr[0])));
			std::vector<int> row5Vect(row5Arr, row5Arr + (sizeof(row5Arr)/sizeof(row5Arr[0])));
			std::vector<int> row6Vect(row6Arr, row6Arr + (sizeof(row6Arr)/sizeof(row6Arr[0])));
			std::vector<int> row7Vect(row7Arr, row7Arr + (sizeof(row7Arr)/sizeof(row7Arr[0])));

			matrixFourByTwo = new Matrix(4, 2);
			matrixFourByTwo->addRow(row4Vect);
			matrixFourByTwo->addRow(row5Vect);
			matrixFourByTwo->addRow(row6Vect);
			matrixFourByTwo->addRow(row7Vect);

			// Create another 4x2 matrix with different values.
			int row8Arr[]	= {9, 10};
			int row9Arr[]	= {11, 12};
			int row10Arr[]	= {13, 14};
			int row11Arr[]	= {15, 16};
			std::vector<int> row8Vect(row8Arr, row8Arr + (sizeof(row8Arr)/sizeof(row8Arr[0])));
			std::vector<int> row9Vect(row9Arr, row9Arr + (sizeof(row9Arr)/sizeof(row9Arr[0])));
			std::vector<int> row10Vect(row10Arr, row10Arr + (sizeof(row10Arr)/sizeof(row10Arr[0])));
			std::vector<int> row11Vect(row11Arr, row11Arr + (sizeof(row11Arr)/sizeof(row11Arr[0])));

			matrixFourByTwo2 = new Matrix(4, 2);
			matrixFourByTwo2->addRow(row8Vect);
			matrixFourByTwo2->addRow(row9Vect);
			matrixFourByTwo2->addRow(row10Vect);
			matrixFourByTwo2->addRow(row11Vect);
		}

		virtual void TearDown() {
			delete matrixThreeByFour;
			delete matrixFourByTwo;
			delete matrixFourByTwo2;
		}
};

// Confirm that the number of rows is correct.
TEST_F(MatrixTest, NumRows){
	ASSERT_THAT(matrixThreeByFour->numRows(), Eq((size_t)3));
}

// Confirm that the number of columns is correct.
TEST_F(MatrixTest, NumColumns){
	ASSERT_THAT(matrixThreeByFour->numColumns(), Eq((size_t)4));
}

// Confirm that rows were added as expected.
TEST_F(MatrixTest, AddRows){
	EXPECT_THAT((*matrixThreeByFour)[0], ElementsAre(1, 2, 3, 4));
	EXPECT_THAT((*matrixThreeByFour)[1], ElementsAre(5, 6, 7, 8));
	EXPECT_THAT((*matrixThreeByFour)[2], ElementsAre(9, 10, 11, 12));
}

// Try to add too many rows.
TEST_F(MatrixTest, AddRowsTooManyRows){
	int rowArr[] = {13, 14, 15, 16};
	std::vector<int> rowVect(rowArr, rowArr + (sizeof(rowArr)/sizeof(rowArr[0])));

	try {
		matrixThreeByFour->addRow(rowVect);
		FAIL() << "Expected std::invalid_argument exception.";
	}
	catch(std::invalid_argument const & err) {
		EXPECT_EQ(err.what(), std::string("Row limit reached."));
	}
	catch(...) {
		FAIL() << "Did not expect any exception other than std::invalid_argument.";
	}

	EXPECT_THAT(matrixThreeByFour->numRows(), Eq((size_t)3));
	EXPECT_THAT((*matrixThreeByFour)[0], ElementsAre(1, 2, 3, 4));
	EXPECT_THAT((*matrixThreeByFour)[1], ElementsAre(5, 6, 7, 8));
	EXPECT_THAT((*matrixThreeByFour)[2], ElementsAre(9, 10, 11, 12));
}

// Try to add a row with too many columns.
TEST(MatrixTestNoFixture, AddRowsTooManyColumns){
	int row1Arr[] = {1, 2, 3, 4};
	int row2Arr[] = {4, 5, 6, 7, 8};
	std::vector<int> row1Vect(row1Arr, row1Arr + (sizeof(row1Arr)/sizeof(row1Arr[0])));
	std::vector<int> row2Vect(row2Arr, row2Arr + (sizeof(row2Arr)/sizeof(row2Arr[0])));
	Matrix matrixTwoByFour(2, 4);

	try {
		matrixTwoByFour.addRow(row1Vect);
		matrixTwoByFour.addRow(row2Vect);
		FAIL() << "Expected std::invalid_argument exception.";
	}
	catch(std::invalid_argument const & err) {
		EXPECT_EQ(err.what(), std::string("Exceeds column limit."));
	}
	catch(...) {
		FAIL() << "Did not expect any exception other than std::invalid_argument.";
	}

	EXPECT_THAT(matrixTwoByFour.numRows(), Eq((size_t)1));
	EXPECT_THAT(matrixTwoByFour.numColumns(), Eq((size_t)4));
	EXPECT_THAT(matrixTwoByFour[0], ElementsAre(1, 2, 3, 4));
}

// Confirm that matrices can be multiplied.
TEST_F(MatrixTest, MatrixMultiply){
	Matrix multiplyResult(3, 2);

	multiplyResult = (*matrixThreeByFour) * (*matrixFourByTwo);

	EXPECT_THAT(multiplyResult[0], ElementsAre(50, 60));
	EXPECT_THAT(multiplyResult[1], ElementsAre(114, 140));
	EXPECT_THAT(multiplyResult[2], ElementsAre(178, 220));
}

// Confirm that matrices can be added.
TEST_F(MatrixTest, MatrixAdd){
	Matrix addResult(4, 2);

	addResult = (*matrixFourByTwo) + (*matrixFourByTwo2);

	EXPECT_THAT(addResult[0], ElementsAre(10, 12));
	EXPECT_THAT(addResult[1], ElementsAre(14, 16));
	EXPECT_THAT(addResult[2], ElementsAre(18, 20));
	EXPECT_THAT(addResult[3], ElementsAre(22, 24));
}





