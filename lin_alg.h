#pragma once

// Matrix template.
template<class T>
class Matrix{
    private:

    public:
        // Constructor.
        Matrix(size_t m, size_t n){
            size_t r = m, c = n;
        }
        // Matrix addition operator. 
        const T& operator+=(const Matrix& A, Matrix& B){
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
        // Matrix addtion method.
        Matrix add(const Matrix& A, Matrix& B){
            Matrix res(A.m, A.n);
            if(A.m != B.m || A.n != B.n){
                throw std::invalid_argument("Matrices are incompatible for addition");
            }
            else{
                for(int i = 0; i < A.m; i++){
                    for(int j = 0;  j < A.n; j++){
                        res[i][j] = A[i][j] + B[i][j];
                    }
                }
                return res;
            }            
        }
        // Matrix subtraction operator.
        const T& operator-=(const Matrix& A, Matrix& B){
            if(A.m != B.m || A.n != B.n){
                throw std::invalid_argument("Matrices are incompatible for subtraction");
            }
            else{
                for(int i = 0; i < A.m; i++){
                    for(int j = 0;  j < A.n; j++){
                        A[i][j] -= B[i][j];
                    }
                }
            }
        }
        // Matrix subtraction method.
        Matrix subtract(const Matrix& A, Matrix& B){
            Matrix res(A.m, A.n);
            if(A.m != B.m || A.n != B.n){
                throw std::invalid_argument("Matrices are incompatible for addition");
            }
            else{
                for(int i = 0; i < A.m; i++){
                    for(int j = 0;  j < A.n; j++){
                        res[i][j] = A[i][j] - B[i][j];
                    }
                }
                return res;
            }            
        }
        // Matrix multiplication method.
        Matrix mutiply(){
            
        }
};
