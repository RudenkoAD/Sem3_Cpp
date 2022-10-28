template <typename T>
class unique_ptr {
  private:
    T* ptr = nullptr;
  public:
    explicit unique_ptr(T* ptr): ptr(ptr) { }
    unique_ptr(): ptr(nullptr) { }

    unique_ptr(unique_ptr& other)=delete;
    unique_ptr(unique_ptr&& other):ptr(other.ptr){
      other.ptr = nullptr;
    }

    unique_ptr& operator=(unique_ptr& other)=delete;
    unique_ptr& operator=(unique_ptr&& other) {
      ptr = other.ptr;
      other.ptr = nullptr;
    }
  
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
  
    ~unique_ptr() {
      if (ptr!=nullptr) delete *ptr;
    }

    void release(){
      if (ptr!=nullptr) delete *ptr;
      ptr=nullptr;
    }

    void swap(unique_ptr& other){
      T* tmp = ptr;
      ptr = other.ptr;
      other.ptr = tmp; 
    }

    void reset(T* pointer){
      release();
      ptr = pointer;
    }

    template <typename U, typename... Args>
    friend unique_ptr<U> make_unique(Args... args);
};


template <typename U, typename... Args>
unique_ptr<U> make_unique(Args... args){
  return unique_ptr<U>(new U(args...));
}