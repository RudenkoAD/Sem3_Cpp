#include <iostream>

using namespace std;


void swag(void* i, void* j, size_t type_size){
    char* ci = static_cast<char*> (i);
    char* cj = static_cast<char*> (j);
    char* tmp = new char;
    for (size_t i =0; i<type_size; i++){
        *tmp = *ci;
        *ci++ = *cj;
        *cj++ = *tmp;
    }
}


int main()
{
    int a, b;
    cin>>a>>b;
    void* i = &a;
    void* j = &b;
    swag(i, j, sizeof(int));
    int in = *(reinterpret_cast<int*>(i));
    int jn = *(reinterpret_cast<int*>(j));
    cout<<in<<' '<<jn;
    
    return 0;
}
