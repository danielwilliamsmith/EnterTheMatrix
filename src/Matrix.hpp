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
		const size_t m_rows;
		const size_t m_columns;

	public:
		Matrix(const size_t rows, const size_t columns);

		void addRow(const std::vector<int> & row);

		void outputMatrix();

		friend Matrix& operator*(const Matrix & m1, const Matrix & m2);

		size_t numRows() { return m_array.size(); }
		size_t numColumns() { return m_array[0].size(); }
};



#endif /* SRC_MATRIX_HPP_ */
