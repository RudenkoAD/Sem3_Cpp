#include <cstdio>
#include <iostream>

template <typename T>
class shared_ptr {
  private:
    template <typename U>
    struct ControlBlock {
          template <typename... Args>
          ControlBlock(Args... args):counter(1), object(args...){}
          size_t counter;
          U object;
        };

    ControlBlock<T>* cptr = nullptr;
    shared_ptr(ControlBlock<T>* cptr): cptr(cptr){}
    template <typename U, typename... Args>
    friend shared_ptr<U> make_shared(Args&&... args);

  public:
    shared_ptr(){}
    shared_ptr(T* ptr): cptr(new ControlBlock<T>(size_t(1), *ptr)){}
  
    shared_ptr(const T& other): cptr(other.cptr) {//copy constructor
      (cptr->counter)++;
    }
    shared_ptr(T&& other): cptr(other.cptr) {//move constructor
      other.cptr=nullptr;
    }

    shared_ptr& operator=(shared_ptr& other){//copy assignment
      delete cptr;
      cptr = other.cptr;
      (cptr->counter)++;
      return *this;
    }
    shared_ptr& operator=(shared_ptr&& other){//move assignment
      cptr=other.cptr;
      other.cptr=nullptr;
      return *this;
    }

    T* get() const{return &(cptr->object);}

    T& operator*() const{return *get();}
    T* operator->() const{return get();}

    size_t use_count() const {
      return cptr->counter;
    }
  
    ~shared_ptr() {
      if(cptr->counter==1) delete cptr;
      else cptr->counter--;
    }
};

template <typename U, typename... Args>
shared_ptr<U> make_shared(Args&&... args){
  return shared_ptr<U>(new typename shared_ptr<U>::ControlBlock<U>(args...));
}

int main(){
  shared_ptr<int> a(make_shared<int>(2));
  shared_ptr<int> b(make_shared<int>(3));
  a=b;
}