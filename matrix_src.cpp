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

template<class T>
Matrix<T> Matrix<T>::operator-=(const Matrix& B){
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

template<class T>
Matrix<T> Matrix<T>::operator*=(const double lambda){
    for(int i = 0; i < this -> m; i++){
        *this -> data[i] *= lambda;
    }
    return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator = (const Matrix& B){
    *this.data.resize(B.data.size(), 0)
    for(int i = 0; i < this -> m; i++){
        *this.data[i] = B.data[i];
    }
    return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator == (const Matrix& B){
    return *this == B;
}

// Member functions
template<class T>
double Matrix<T>::trace(){ // Function to find trace.
        double ans = 0;
        if(this -> n != A.n){
            throw std::invalid_argument("Matrix is not square");
        }
        for(int i = 0. j = 0; i < this -> m && j < this -> m; i++, j++){
            ans += *this[i][j];
        }
        return ans;
    }

template<class T>
    Matrix<T> Matrix<T>::T(){ // Transpose function.
        std::vector<T> temp(*this.m * *this.n, 0);
        // Load the temp vector.
        for(int i = 0; i < *this.m; i++){
            for(int j = 0; j < *this.n; j++){
                temp[*this.m*i + j] = *this.data[i][j];
            }
        }
    }

template<class T>
    double Matrix<T>::det(){
            // Check if the matrix is square or not.
            double ratio, determinant;
            Matrix<T> tmp = *this;
            if(tmp.m != tmp.n){
                throw std::invalid_argument("Matrix is not square.");
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
