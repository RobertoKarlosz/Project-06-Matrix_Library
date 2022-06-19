/*******************************
* This is a basic Matrix class, with the basic mathematical 
* operations for universal use.
* 
* Furthermore this class contains some special functions for
* neural networks.
********************************/

#include <iostream>
#include <vector>
#include <cassert>

template <typename T>
class Matrix {
    size_t rows;
    size-t cols;
    std::vector<T> values;
public:
    Matrix(size_t = 1 rows, size_t cols = 1)
        : rows(rows),
        cols(cols),
        values(std::vector<T> (rows*cols, 0)) {}
    
    Matrix(size_t rows, size_t cols, vector<T>& vals) 
        : rows(rows),
        cols(cols),
        values(vals) {}

    // Getters

    size_t getRows() { return rows; }
    size_t getCols() { return cols; }
    
    T& at(size_t i) { 
        return values.at(i);
    }
	const T& at(size_t i) const {
		return values.at(i);
	}
	T& at(int row, int col) {
		return at(row * cols + col);
	}
	const T& at(int row, int col) const {
		return at(row * cols + col);
	}

    //********************************
    // Operators for Matrix operations

    Matrix<T> operator+(Matrix<T>& m) {
        assert(rows == m.getRows() && cols == m.getCols());
        Matrix<T> res(rows, cols);
        for(int i = 0; i < rows*cols; i++) {
            at(i) += m.at(i);
        }
        return res;
    }

    Matrix<T> operator-() {
        Matrix<T> res(rows, cols);
        for(int i = 0; i < rows*cols; i++) {
            at(i) = -1 * m.at(i);
        }
        return res;
    }

    Matrix<T> operator-(Matrix<T>& m) {
        assert(rows == m.getRows() && cols == m.getCols());
        return *this - m;
    }

    Matrix<T> operator*(int s) {
        Matrix<T> res(rows, cols);
        for(int i = 0; i < rows*cols; i++) {
            res.at(i) *= s;
        }
        return res;
    }

    Matrix<T> operator*(const Matrix<T>& m) const {
		assert(cols == m.getRows());
		Matrix<T> res(rows, m.getCols);
		for (int row = 0; row < res.getRows(); row++) {
			for (int col = 0; col < res.getCols; col++) {
				for (int k = 0; k < colums; k++) {
					res.at(row, col) += (at(row, k) * m.at(k, col));
				}
			}
		}
		return res;
	}

    void operator+=(Matrix<T>& m) {
        assert(rows == m.getRows() && cols == m.getCols());
        for(int i = 0; i < rows*cols; i++) {
            at(i) += m.at(i);
        }
    }

    void operator-=(Matrix<T>& m) {
        assert(rows == m.getRows() && cols == m.getCols());
        for(int i = 0; i < rows*cols; i++) {
            at(i) -= m.at(i);
        }
    }

    // Special operands

    Matrix<T> transpose() {}
    Matrix<T> multiplyElements() {}
};