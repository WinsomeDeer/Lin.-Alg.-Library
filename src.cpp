#include "patlab.h"

// Constructor definition.
template<class T>
Matrix<T>::Matrix(const int i, const int j){
    size_t m = i, n = j;
}

// Operator definitions.
template<class T>
Matrix<T> Matrix<T>::operator () (const int& i, const int& j){
        if(i > this -> m || j > this -> n){
            throw std::invalid_argument("Index out of bounds");
        }
        return this -> std::data[(i * this -> m) + j];
    }

template<class T>
Matrix<T> Matrix<T>::operator += (const Matrix& B){
    if(*this -> m != B.m || *this -> n != B.n){
        throw std::invalid_argument("Matrices are incompatible for addition");
    }
    else{
        for(int i = 0; i < this -> m; i++){
            for(int j = 0;  j < this -> n; j++){
                *this.data[i*this -> m + j] += B.data[i*this -> m + j];
            }
        }
    }
    return *this;
}
