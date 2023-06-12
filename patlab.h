#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

// Matrix template.
template<class T>
class Matrix{
    private:
        std::vector<T> data = int_list;
    public:
        // Constructor.
        Matrix(const int m, const int n);
        // Get element operator
        Matrix<T> operator()(const int& i, const int& j);
        // Matrix addition operator. 
        Matrix<T> operator+=(const Matrix& B);
        // Matrix subtraction operator.
        Matrix<T> operator-=(const Matrix& B);
        // Scalar multiplication operator.
        Matrix<T> operator*=(const double lambda);
        // Assignment operator.
        Matrix<T> operator=(const Matrix& B);
        // Equality operator.
        Matrix<T> operator==(const Matrix& B);
        // Method to compute the trace.
        double trace();
        // Matrix transpose method.
        Matrix<T> T();
        // Method to find the determinant of Matrix - put matrix in R.E. form.
        double det();
};
