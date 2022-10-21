#include <iostream>

template <typename T>
struct Comparator {
    virtual bool operator()(T const &, T const &) const = 0;
};

struct IntComparator final: virtual Comparator<int> {
    bool operator()(int const &lha, int const &rha) const override {
        return lha < rha;
    }
};

template <typename T>
struct DumbComparator final: virtual Comparator<T>{
    bool operator()(T const &lha, T const &rha) const override {
        return &lha > &rha;
    }
};

template <typename T>
int qs(T* const begin, T* const end, Comparator<T> const & comp){
    T* i = begin;
    T* j = end-1;
    int size = (end-begin);
    T* anchor = begin+(size/2);
    do {
        while (comp(*i, *anchor)) i++;
        while (comp(*anchor, *j)) j--;
  
        if(i <= j) {
            if (comp(*j, *i)) std::swap(*i, *j);
            i++;
            j--;
        }
    } while (i <= j);
  
    if (i < end)
        qs<T>(i, end, comp);
    if (begin < j)
        qs<T>(begin, j+1, comp);
    return size;
}

template <typename T, typename Comparator = DumbComparator<T>>
class PriorityQueue{
    private:
        T* data;//an array of size max_size, we use only [0, size) for storage
        Comparator comp;
        int size;
        int max_size;
        
        static int parent(int i) {
            return (i - 1) / 2;
        }

        static int leftChild(int i) {
            return 2*i + 1;
        }
        
        static int rightChild(int i) {
            return 2*i + 2;
        }

        static void swap(T *x, T *y) {
            T temp = *x;
            *x = *y;
            *y = temp;
        }

        void insert(T elem) {
            if(size==max_size){
                std::cout<<"max size exceeded";
                return;
            }
            data[size] = elem;
            size = size + 1;
            // move up until the data property satisfies
            int i = size - 1;
            while (i != 0 && comp(data[parent(i)], data[i])) {
                swap(&data[parent(i)], &data[i]);
                i = parent(i);
            }
        }

        void fix(int i){//drop the element number i down
            int left = leftChild(i);
            int right = rightChild(i);
            int largest = i;

            if (left < size && comp(data[largest], data[left])) {
                largest = left;
            }

            if (right < size &&  comp(data[largest], data[right])) {
                largest = right;
            }

            if (largest != i) {
                int temp = data[i];
                data[i] = data[largest];
                data[largest] = temp;
                fix(largest);
            }

        }

        void init(){//fix the heap from a random array
            for(int i=size-1; i>=0; i--){
                fix(i);
            }
        }

        void free(){
            delete[] data;
        }

    public:
        PriorityQueue(): comp(), size(0), max_size(10){
            data = new T[max_size];
        }

        PriorityQueue(T* const begin, T* const end, int max_size, Comparator const & comp): comp(comp), size(end-begin), max_size(2*size){
            data = new T[max_size];
            for (auto it=begin, i=0; it!=end; it++, i++){
                data[i]=*it;
            }
            init();
        }

        void push(T const& elem){
            insert(elem);
        }
        
        T* peek() const{
            return data;
        }
        
        void poll(){
            swap(data, data+(size-1));
            size=size - 1;
            fix(0);
        }

        bool is_empty() const{
            return size!=0;
        }

        ~PriorityQueue(){
            free();
        }
};


int main(){
    IntComparator comp;
    int a[5] = {1, 4, 2, 3, 5};
    PriorityQueue<int, IntComparator> c = PriorityQueue(a, a+5, 10, comp);
    c.push(6);
    std::cout<<*c.peek();
    c.poll();
    std::cout<<c.is_empty();
    return 0;
}