
template <typename T, int N>//A N-D Grid
class Grid final{
  public:
    using size_type=unsigned; 
  private:
    Grid<T, N-1>* data;
    size_type y_size;
    void free(){
      delete[] data;
    }
  public:
    //constructors
    //argument constructors
    Grid(T const &t):y_size(1){
      data = new Grid<T, N-1>[1];
      data[0]=Grid<T, N-1>(t);
    }
    Grid():Grid(1){}
    template <typename... Sizes>
    Grid(T const &t, size_type y_size, Sizes... sizes): y_size(y_size){
      data = new Grid<T, N-1>[y_size];
      for(int i=0; i<y_size; i++){
        data[i] = Grid<T, N-1>(t, sizes...);
      }
    }
    //copy constructor
    Grid(Grid<T, N> const & src): y_size(src.y_size){
      for(size_type i=0; i<y_size; i++){
        data[i] = src.data[i];
      }
    }
    //move constructor
    Grid (Grid<T, N>&& src):data(src.data), y_size(src.y_size){
      src.data=nullptr;
    }
    //destructor
    ~Grid(){
      delete[] data;
    }
    
    //functions
    size_type get_y_size() const {return y_size;}
    size_type get_x_size() const {return data[0].get_y_size();}
    
    //operators
    //copy assignment
    Grid<T, N>& operator=(Grid<T, N>& src){
      free();
      for(int i=0; i<y_size; i++){
        data[i] = src[i];
      }
      y_size = src.y_size;
      return *this;
    }
    //move assignment
    Grid<T, N>& operator=(Grid<T, N>&& src){
      free();
      data = src.data;
      y_size = src.y_size;
      return *this;
    }
    //fill with T
    Grid<T, N>& operator=(T const &t) {
      for(size_type i=0; i<y_size; i++){
        data[i]=t;
      }
      return *this;
    }
    //getters via []
    Grid<T, N-1> operator[](size_type y_idx) const{
      return data[y_idx];
    }
    Grid<T, N-1>& operator[](size_type y_idx){
      return data[y_idx];
    }
};

template <typename T>//A 1-D Grid as a final iteration of the N-D Grid Essentially identical to T[size]
class Grid<T, 1>{
  public:
    using size_type=unsigned; 
  private:
    T* data;
    size_type size_y;
  public:
    //constructors
    //argument constructors
    Grid():size_y(1){
      data=new T[1];
    }
    Grid(T *src, size_type size): size_y(size) {
      data = new T[size];
      for(int i=0; i<size_y; i++){
        data[i] = src[i];
      }
    }
    Grid(T const &t):size_y(1){
      data = new T[1];
      data[0]=t;
    }
    Grid(size_type size): size_y(size){
      data = new T[size_y];
    }
    Grid(size_type size, T const &t):size_y(size){
      data = new T[size_y];
      for (auto it = data, end = data + size_y; it != end; ++it) 
        *it = t;
    }
    //copy constructor
    Grid(Grid<T, 1> const & src): Grid(src.data, src.size_y){}
    //move constructor
    Grid(Grid<T, 1>&& src):data(src.data), size_y(src.size_y){
      src.data=nullptr;
    }
    //destructor
    ~Grid(){
      delete[] data;
    }
    
    //functions
    size_type get_y_size() const {return size_y;}
    size_type get_x_size() const {return 1;}
    void free(){
      delete[] data;
    }
    
    //operators
    //copy assignment
    Grid<T, 1>& operator=(Grid<T, 1>& src){
      free();
      for(int i=0; i<size_y; i++){
        data[i] = src[i];
      }
      size_y = src.size_y;
      return *this;
    }
    //move assignment
    Grid<T, 1>& operator=(Grid<T, 1>&& src){
      free();
      data = src.data;
      size_y = src.size_y;
      return *this;
    }
    //fill with T
    Grid<T ,1>& operator=(T const &t) {
      for (auto it = data, end = data + size_y; it != end; ++it) 
        *it = t;
      return *this;
    }
    //getters via []
    T operator[](size_type y_idx) const{
      return data[y_idx];
    }
    T& operator[](size_type y_idx) {
      return data[y_idx];
    }
}; 


#include <cassert>
/*
int main ( ) {
Grid<float, 2> g (3, 2, 0.0f);
assert(3 == g.get_y_size());
assert(2 == g.get_x_size());
for(unsigned y_idx = 0 ; y_idx != g.get_y_size () ; ++y_idx )
  for(unsigned x_idx = 0 ; x_idx != g.get_x_size () ; ++x_idx )
    assert(0.0f==g[y_idx][x_idx]);
for(unsigned y_idx = 0 ; y_idx != g.get_y_size () ; ++y_idx )
  for(unsigned x_idx = 0 ; x_idx != g.get_x_size () ; ++x_idx )
    g[y_idx][x_idx]=1.0f;
for(unsigned y_idx = 0 ; y_idx != g.get_y_size () ; ++y_idx )
  for(unsigned x_idx = 0 ; x_idx != g.get_x_size () ; ++x_idx )
    assert(1.0f == g[y_idx][x_idx]);
return 0;
}*/


int main(){
  Grid<float ,3> const g3 (1.0f, 2, 3, 4);
  assert(1.0f == g3[1][1][1]);
  Grid<float, 2> g2(2.0f, 2, 5);
  assert( 2.0f == g2[1][1]);
  g2 = g3[1];
  assert( 1.0f == g2[1][1]);
}