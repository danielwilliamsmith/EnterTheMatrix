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
		unsigned int m_arrayAddPos;

	public:
		Matrix(size_t row, size_t column);

		void addRow(const std::vector<int>& data);

		void outputMatrix();

};



#endif /* SRC_MATRIX_HPP_ */
