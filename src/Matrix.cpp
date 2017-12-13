/*
 * Matrix.cpp
 *
 *  Created on: Dec 13, 2017
 *      Author: dws
 */


#include "Matrix.hpp"

#include <iostream>
#include <vector>

// Matrix Constructor.
Matrix::Matrix(size_t row, size_t column):m_array(row, std::vector<int>(column)), m_arrayAddPos(0){}

void Matrix::addRow(const std::vector<int>& data)
{
	m_array[m_arrayAddPos++] = data;
}

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

int main()
{
	Matrix myMatrix(3, 3);

	int row1Arr[] = {1, 2, 3};
	int row2Arr[] = {4, 5, 6};
	int row3Arr[] = {7, 8, 9};

	std::vector<int> row1Vec(row1Arr, row1Arr+3);
	std::vector<int> row2Vec(row2Arr, row2Arr+3);
	std::vector<int> row3Vec(row3Arr, row3Arr+3);

	myMatrix.addRow(row1Vec);
	myMatrix.addRow(row2Vec);
	myMatrix.addRow(row3Vec);

	myMatrix.outputMatrix();

	return 0;
}

