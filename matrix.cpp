#include <algorithm>
#include <iostream>
#include <vector>

// Matrix template.
template<class T>
class Matrix{
    public:
        // Constructor.
        Matrix(vector<vector<T>>& int_list){
            size_t m = int_list.size(), n = int_list[0].size();
            vector<vector<T>> data = int_list;
        }
        // Get element operator.
        const operator()(const int i, const int j){
            return A.data[i][j];
        }
        // Matrix addition operator. 
        const T& operator+=(Matrix& A, const Matrix& B){
            if(A.m != B.m || A.n != B.n){
                throw std::invalid_argument("Matrices are incompatible for addition");
            }
            else{
                for(int i = 0; i < A.m; i++){
                    for(int j = 0;  j < A.n; j++){
                        A[i][j] += B[i][j];
                    }
                }
            }
        }
        // Matrix subtraction operator.
        const T& operator-=(Matrix& A, const Matrix& B){
            if(A.m != B.m || A.n != B.n){
                throw std::invalid_argument("Matrices are incompatible for subtraction");
            }
            else{
                for(int i = 0; i < A.m; i++){
                    for(int j = 0;  j < A.n; j++){
                        A.data[i][j] -= B[i][j];
                    }
                }
            }
        }
        // Matrix transpose method.
        Matrix T(){
            vector<int> temp(A.m * A.n, 0);
            // Load the temp vector.
            for(int i = 0; i < A.m; i++){
                for(int j = 0; j < A.n; j++){
                    temp[A.m*i + j] = A.data[i][j];
                }
            }
            // Swap the dimensions.
            swap(A.m, A.n);
            k = 0;
            // Put elements back into new transposed matrix.
            for(int i = 0; i < A.m; i++){
                for(int j = 0; j < A.n; j++){
                    A.data[i][j] = temp[k];
                    k++;
                }
            }
            return A;
        }
        // Print method.
        void print(){
            for(int i = 0; i < A.m; i++){
                for(int j = 0; j < A.n; j++){
                    std::cout << A.data[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }
        // Method to find the determinant of Matrix A - det(A) = det(L)*det(U).
        Matrix det(){
            // Check if the matrix is square or not.
            if(A.m != A.n){
                throw std::invalid_argument("Matrix is not square.")
            }
            // Row echelon form algorithm to find the upper and lower tri. matrices.
            for(int i = ...)
        } 
};
