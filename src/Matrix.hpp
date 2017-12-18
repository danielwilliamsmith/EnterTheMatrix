/*
 * Matrix.hpp
 *
 *  Created on: Dec 13, 2017
 *      Author: dws
 */

#ifndef SRC_MATRIX_HPP_
#define SRC_MATRIX_HPP_

#include <vector>

class Matrix
{
	private:
		std::vector<std::vector<int>> m_array;
		size_t m_rows;
		size_t m_columns;

	public:
		// Constructor that places limits on rows and columns.
		Matrix(const size_t rows, const size_t columns);
		// Constructor with limits and an initial value.
		Matrix(const size_t rows, const size_t columns, int data);

		void addRow(const std::vector<int>& row);

		void outputMatrix();

		friend Matrix operator*(Matrix& m1, Matrix& m2);
		friend Matrix operator+(Matrix& m1, Matrix& m2);

		std::vector<int>& operator[] (const size_t i) { return m_array[i]; }

		size_t numRows() { return m_array.size(); }
		size_t numColumns() { return m_array[0].size(); }
};

#endif /* SRC_MATRIX_HPP_ */
