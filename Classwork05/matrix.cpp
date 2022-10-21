#include <cstdio>
#include <iostream>

template<typename Field, std::size_t M, std::size_t N>
class Matrix {
  private:
    Field data[M][N];
  public:
    //initialisers
    Matrix():data(){}
    Matrix(Field src[M*N]){
      for(size_t i=0; i<M*N; i++){
        data[i/M][i%M]=src[i];
      }
    }
    Matrix(Field src[M][N]): data(src){}

    //functions and operators
    Matrix<Field, M, N>* operator=(const Matrix<Field, M, N>& rha) {
      for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
          data[i][j]=rha[i][j];
        }
      }
      return this;
    }

    int* operator[](size_t id){
      return data[id];
    }

    int const* operator[](size_t id) const{
      return data[id];
    }

    void print(){
      for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
          std::cout<<data[i][j];
        }
        std::cout<<std::endl;
      }
    }

    //friend declarations
    template<typename F, std::size_t Ma, std::size_t Na, std::size_t Ka>
    friend Matrix<F, Ma, Ka> operator*(const Matrix<F, Ma, Na>& lha, const Matrix<F, Na, Ka>& rha);
    
    template<typename F, std::size_t Ma, std::size_t Na, std::size_t Ka>
    friend Matrix<F, Ma, Na> operator+(const Matrix<F, Ma, Na>& lha, const Matrix<F, Ma, Na>& rha);
    
    template<typename F, std::size_t Ma, std::size_t Na, std::size_t Ka>
    friend Matrix<F, Ma, Na> operator-(const Matrix<F, Ma, Na>& lha, const Matrix<F, Ma, Na>& rha);
};

//operators

template<typename F, std::size_t Ma, std::size_t Na, std::size_t Ka>
Matrix<F, Ma, Ka> operator*(const Matrix<F, Ma, Na>& lha, const Matrix<F, Na, Ka>& rha) {
  Matrix<F, Ma, Ka> ans;
  for (int i=0; i<Ma; i++){
    for (int j=0; j<Ka; j++){
      for (int k=0; k<Na; k++){
        ans[i][j]+=lha[i][k]*rha[k][j];
      }
    }
  }
  return ans;
}

template<typename F, std::size_t Ma, std::size_t Na>
Matrix<F, Ma, Na> operator+(const Matrix<F, Ma, Na>& lha, const Matrix<F, Ma, Na>& rha) {
  Matrix<F, Ma, Na> ans;
  for (int i=0; i<Ma; i++){
    for (int j=0; j<Na; j++){
      ans[i][j]=lha[i][j]+rha[i][j];
    }
  }
  return ans;
}

template<typename F, std::size_t Ma, std::size_t Na>
Matrix<F, Ma, Na> operator-(const Matrix<F, Ma, Na>& lha, const Matrix<F, Ma, Na>& rha) {
  Matrix<F, Ma, Na> ans;
  for (int i=0; i<Ma; i++){
    for (int j=0; j<Na; j++){
      ans[i][j]=lha[i][j]-rha[i][j];
    }
  }
  return ans;
}

//Main

int main(){
    const size_t a = 2;
    const size_t b = 2;
    int c[4] = {1, 0, 1, 1};
    Matrix<int, a, b> test1 = Matrix<int, a, b>(c);
    Matrix<int, a, b> test2 = Matrix<int, a, b>(c);
    Matrix<int, a, b> test3 = test1*test2;
    test3.print();
    return 0;
}