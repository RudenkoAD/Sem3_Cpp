#include <iostream>

using namespace std;

bool compare(void* a, void* b){
    int* i = static_cast<int*>(a);
    int* j = static_cast<int*>(b);
    return (*i<=*j);
}

int min(void* arr, int arr_size, int type_size, bool (*compare)(void *, void *)){
    int mini = 0;
    for (int i=0; i<arr_size; i++){
        if(!compare(arr+mini*type_size, arr+i*type_size)) mini = i;
    }
    return mini;
}

int main()
{
    int a[5] = {2,3,4,1,6};
    int arr_size = 5;
    int type_size = sizeof(int);
    cout<<type_size<<endl;
    bool (*comp)(void*, void*);
    comp = compare;
    cout<<min(a, arr_size, type_size, comp);
}
