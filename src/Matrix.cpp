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
Matrix::Matrix(const size_t rows, const size_t columns): m_rows(rows), m_columns(columns) {
	m_array.reserve(rows);
}

// Add a new row to the matrix.  It is always added after the last row.
void Matrix::addRow(const std::vector<int> & row)
{
	if((m_array.size() < m_rows) && (row.size() == m_columns))
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

/*
Matrix& operator*(const Matrix& m1, const Matrix& m2)
{
	std::vector<std::vector<int>>::const_iterator iM1;
	std::vector<std::vector<int>>::const_iterator iM2;
	std::vector<std::vector<int>>::const_iterator iMResult;

    // Multiply the two matrices
    for (int i = 0 ; i < ROWS ; i++)
    {
        for (int k = 0; k < COLUMNS; k++)
        {
            for (int j = 0 ; j < COLUMNS ; j++)
            {
                matrix_r[i][j] = matrix_r[i][j] + matrix_a[i][k] * matrix_b[k][j] ;
            }
        }
    }
}
*/

/*
int main()
{
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

	myMatrix.outputMatrix();

	return 0;
}
*/

