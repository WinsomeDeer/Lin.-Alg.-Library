#pragma once

// Matrix template.
template<class T>
class Matrix{
    private:

    public:
        Matrix(size_t m, size_t n){
            size_t r = m, c = n;
        }
        // Matrix addition operator. 
        const T& operator+(const Matrix& A, Matrix& B){
            if(A.m != B.m || A.n != B.n){
                throw std::invalid_argument("Matrices are incompatible for addition");
            }
        }
};
