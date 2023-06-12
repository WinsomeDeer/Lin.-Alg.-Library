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
        Matrix<T> operator-=(const Matrix& B){
            if(this -> n != B.m || this -> m != B.n){
                throw std::invalid_argument("Matrices are incompatible for subtraction");
            }
            else{
                for(int i = 0; i < this -> m; i++){
                    for(int j = 0;  j < this -> n; j++){
                        *this.data[i][j] -= B[i][j];
                    }
                }
            }
            return *this;
        }
        // Scalar multiplication operator.
        Matrix<T> operator*=(const double lambda){
            for(int i = 0; i < this -> m; i++){
                *this -> data[i] *= lambda;
            }
            return *this;
        }
        // Assignment operator.
        Matrix<T> operator=(const Matrix& B){
            *this.data.resize(B.data.size(), 0)
            for(int i = 0; i < this -> m; i++){
                *this.data[i] = B.data[i];
            }
            return *this;
        }
        // Equality operator.
        Matrix<T> operator==(const Matrix& B){
            return *this == B;
        }
        // Method to compute the trace.
        double trace(){
            double ans = 0;
            if(this -> n != A.n){
                throw std::invalid_argument("Matrix is not square");
            }
            for(int i = 0. j = 0; i < this -> m && j < this -> m; i++, j++){
                ans += *this[i][j];
            }
            return ans;
        }
        // Matrix transpose method.
        Matrix<T> T(){
            vector<T> temp(*this.m * *this.n, 0);
            // Load the temp vector.
            for(int i = 0; i < *this.m; i++){
                for(int j = 0; j < *this.n; j++){
                    temp[*this.m*i + j] = *this.data[i][j];
                }
            }
            // Swap the dimensions.
            swap(*this.m, *this.n);
            int k = 0;
            // Put elements back into new transposed matrix.
            for(int i = 0; i < this -> m; i++){
                for(int j = 0; j < this -> n; j++){
                    *this.data[i][j] = temp[k];
                    k++;
                }
            }
            return *this;
        }
        // Method to find the determinant of Matrix A - put matrix in R.E. form.
        double det(){
            // Check if the matrix is square or not.
            double ratio, determinant;
            Matrix tmp = *this;
            if(tmp.m != tmp.n){
                throw std::invalid_argument("Matrix is not square.")
            }
            // Put matrix in R.E form.
            for(int i = 0; i < tmp.m - 1; i++){
                for(int j = tmp.m - 1, j > i, j--){
                    if(tmp[j][i] == 0){
                        continue;
                    }
                    else{
                        try{
                            ratio = tmp[j][i]/tmp[j-1][i];
                            for(int k = 0; k < this -> m; k++){
                                swap(tmp[j][k], tmp[j-1][k])
                            }
                        }
                        continue;
                    }
                    for(int l = 0; l < this -> m; l++){
                        tmp[j][l] = tmp[j][l] - ratio*tmp[j-1][k];
                    }
                }
            }
            // Multiply the entries on the trace diagonal.
            determinant = tmp[0][0];
            for(int i = 1, j = 1; i, j < tmp.m; i++, j++){
                determinant *= tmp[i][j];
            }
            return determinant;
        }
};
