/*
 * Matrix.cpp
 *
 *  Created on: Dec 13, 2017
 *      Author: dws
 */

#include "Matrix.hpp"

#include <iostream>
#include <stdexcept>
#include <vector>

// Matrix constructor without any initial data.
Matrix::Matrix(size_t rows, size_t columns): m_rows(rows), m_columns(columns) {
	m_array.reserve(rows);
}

// Matrix constructor with initial data.
Matrix::Matrix(size_t rows, size_t columns, int data): m_rows(rows), m_columns(columns) {
	m_array.reserve(rows);

	std::vector<int> initialize(columns, data);
	for(unsigned int i = 0; i < m_rows; i++)
	{
		m_array.push_back(initialize);
	}
}

// Add a new row to the matrix.  It is always added after the last row.
void Matrix::addRow(const std::vector<int>& row)
{
	if(m_array.size() >= m_rows)
	{
		throw std::invalid_argument("Row limit reached.");
	}
	else if (row.size() != m_columns)
	{
		throw std::invalid_argument("Exceeds column limit.");
	}
	else
	{
		m_array.push_back(row);
	}
}

// Display the current state of the matrix in the console.
void Matrix::outputMatrix()
{
	std::vector<std::vector<int>>::const_iterator iRow;
	std::vector<int>::const_iterator iColumn;

	for(iRow = m_array.begin(); iRow != m_array.end(); ++iRow)
	{
		for(iColumn = (*iRow).begin(); iColumn != (*iRow).end(); ++iColumn)
		{
			std::cout << *iColumn << ' ';
		}
		std::cout << '\n';
	}
}

Matrix operator*(Matrix& m1, Matrix& m2)
{
	// Check to see if multiplication is possible with the given inputs.
	if(m1.numColumns() != m2.numRows())
	{
		throw std::invalid_argument("Number of left hand side matrix columns "
				"must equal number of right hand side matrix rows.");
	}

	const size_t resultRows = m1.numRows();
	const size_t resultColumns = m2.numColumns();
	const size_t shared = m1.numColumns();
	Matrix mResult(resultRows, resultColumns, 0);

	for (unsigned int iRows = 0; iRows < resultRows; iRows++)
	{
		for (unsigned int iShared = 0; iShared < shared; iShared++)
		{
			for (unsigned int iColumns = 0; iColumns < resultColumns; iColumns++)
			{
				mResult[iRows][iColumns] =
						mResult[iRows][iColumns] + m1[iRows][iShared] * m2[iShared][iColumns];
			}
		}
	}
	return mResult;
}

Matrix operator+(Matrix& m1, Matrix& m2)
{
	// Check to see if addition is possible with the given inputs.
	if((m1.numRows() != m2.numRows()) &&
			(m1.numColumns() != m2.numColumns()))
	{
		throw std::invalid_argument("Matrices must be equal size.");
	}

	const size_t resultRows = m1.numRows();
	const size_t resultColumns = m1.numColumns();
	Matrix mResult(resultRows, resultColumns, 0);

	for (unsigned int iRows = 0; iRows < resultRows; iRows++)
	{
		for (unsigned int iColumns = 0; iColumns < resultColumns; iColumns++)
		{
			mResult[iRows][iColumns] = m1[iRows][iColumns] + m2[iRows][iColumns];
		}
	}

	return mResult;
}

/*
int main()
{
	int row1Arr[] = {1, 2, 3, 4};
	int row2Arr[] = {4, 5, 6, 7};
	std::vector<int> row1Vect(row1Arr, row1Arr + (sizeof(row1Arr)/sizeof(row1Arr[0])));
	std::vector<int> row2Vect(row2Arr, row2Arr + (sizeof(row2Arr)/sizeof(row2Arr[0])));
	Matrix matrixTwoByFour(2, 4);

	matrixTwoByFour.addRow(row1Vect);
	matrixTwoByFour.addRow(row2Vect);

	std::cout << matrixTwoByFour[0][0] << " ";
	std::cout << matrixTwoByFour[0][1] << " ";
	std::cout << matrixTwoByFour[0][2] << " ";
	std::cout << matrixTwoByFour[0][3] << " " << std::endl;
	std::cout << matrixTwoByFour[1][0] << " ";
	std::cout << matrixTwoByFour[1][1] << " ";
	std::cout << matrixTwoByFour[1][2] << " ";
	std::cout << matrixTwoByFour[1][3] << " " << std::endl;
}
*/
