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
        Matrix(vector<vector<T>>& int_list){
            size_t m = int_list.size(), n = int_list[0].size();
        }
        // Get element operator.
        Matrix<T> operator[](const int i, const int j){
            if(i > *this.m || j > *this.n){
                throw std::invalid_argument("Index out of bounds");
            }
            return *this.data[i*A.m + j];
        }
        // Matrix addition operator. 
        Matrix<T> operator+=(Matrix const& B){
            if(*this.m != B.m || *this.n != B.n){
                throw std::invalid_argument("Matrices are incompatible for addition");
            }
            else{
                for(int i = 0; i < A.m; i++){
                    for(int j = 0;  j < A.n; j++){
                        *this.data[i*A.m + j] += B.data[i*B.m + j];
                    }
                }
            }
            return *this;
        }
        // Matrix subtraction operator.
        Matrix<T> operator-=(const Matrix& B){
            if(A.m != B.m || A.n != B.n){
                throw std::invalid_argument("Matrices are incompatible for subtraction");
            }
            else{
                for(int i = 0; i < A.m; i++){
                    for(int j = 0;  j < A.n; j++){
                        *this.data[i][j] -= B[i][j];
                    }
                }
            }
            return *this;
        }
        // Scalar multiplication operator.
        Matrix<T> operator*=(const int lambda){
            for(int i = 0; i < A.m; i++){
                *this.data[i] *= lambda;
            }
            return *this;
        }
        // Assignment operator.
        Matrix<T> operator=(const Matrix& B){
            *this.data.resize(B.data.size(), 0)
            for(int i = 0; i < A.m; i++){
                *this.data[i] = B.data[i];
            }
            return *this;
        }
        double trace(){
            double ans = 0;
            if(A.m != A.n){
                throw std::invalid_argument("Matrix is not square");
            }
            for(int i = 0. j = 0; i, j < A.m; i++, j++){
                ans += *this[i][j];
            }
            return ans;
        }
        // Matrix transpose method.
        Matrix<T> T(){
            vector<int> temp(*this.m * *this.n, 0);
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
            for(int i = 0; i < A.m; i++){
                for(int j = 0; j < A.n; j++){
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
                            for(int k = 0; k < A.m; k++){
                                swap(tmp[j][k], tmp[j-1][k])
                            }
                        }
                        continue;
                    }
                    for(int l = 0; l < tmp.m; l++){
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
