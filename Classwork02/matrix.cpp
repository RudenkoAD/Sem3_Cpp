#include <iostream>
#include <bits/stdc++.h>

class Matrix {
    public:
        Matrix(int* arr, size_t n) : tsize(n){///initialize by a list of size n*n
            int** mat = new int*[n];
            for (int i=0; i<n; i++){
                int* row = new int[n];
                for (int j=0; j<n; j++){
                    row[j]=arr[i*n+j];
                }
                mat[i]=row;
            }
            this->mat = mat;
        }

        Matrix(int element, size_t n) : tsize(n){///initialize by a single element, filling the matrix with it
            int** mat = new int*[n];
            for (int i=0; i<n; i++){
                int* row = new int[n];
                for (int j=0; j<n; j++){
                    row[j]=element;
                }
                mat[i]=row;
            }
            this->mat = mat;
        }

        Matrix(): tsize(1){///initialize by default as a 1x1 matrix with an integer 1
            int** mat = new int*[1];
            int* row = new int[1];
            mat[0]=row;
            this->mat = mat;
        }

        Matrix(const Matrix& other): tsize(other.tsize){///initialise as a deep copy of another matrix
            int** mat = new int*[other.tsize];
            for (int i=0; i<other.tsize; i++){
                int* row = new int[other.tsize];
                for (int j=0; j<other.tsize; j++){
                    row[j]=other.mat[i][j];
                }
                mat[i]=row;
            }
            this->mat = mat;
        }

        ~Matrix(){
            for (int i=0; i<tsize; i++){
                delete[] mat[i];
            }
            delete[] mat;
        }

        void printMatrix() const {
            for (int i=0; i<tsize; i++){
                for (int j=0; j<tsize-1; j++){
                    std::cout<<mat[i][j]<<" ";
                }
                std::cout<<mat[i][tsize-1]<<std::endl;
            }
        }
    
        int calcDeterminant() const {
            //TODO
            return 0;
        }
    
        Matrix operator* (Matrix const right) const{
            int* row = new int[tsize*tsize];
            for (int i=0; i<tsize; i++){
                for (int j=0; j<tsize; j++){
                    int sum=0;
                    for(int k=0; k<tsize; k++){
                        sum+=(this->mat[i][k])*right.mat[k][j];
                    }
                    row[i*tsize + j] = sum;
                }
            }
            Matrix result = Matrix(row, tsize);
            delete[] row;
            return result;
        }

        void calcSquare() const {
            ((*this)*(*this)).printMatrix();
        }

        void matTranspose() {///transpose the matrix
            int temp;
            for(int i=0; i<tsize; i++){
                for(int j=0; j<tsize; j++){
                    temp = mat[i][j];
                    mat[i][j]=mat[j][i];
                    mat[j][i]=temp;
                }
            }
        }
    
    private:
        int tsize;
        int** mat;

        int factorial(int i) const{
            int ans = 1;
            for(int j=2; j<=i; j++){
                ans*=j;
            }
            return ans;
        }
        
};

int main(){
    return 0;
}