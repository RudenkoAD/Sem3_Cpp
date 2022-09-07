#include <iostream>

using namespace std;

bool compare(void* a, void* b){
    int* i = static_cast<int*>(a);
    int* j = static_cast<int*>(b);
    return (*i<=*j);
}

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


void qsort(void* arr, int left, int right, size_t type_size, bool (*compare)(void *, void *)){
    if (left >= right) return;

    void* anchor = arr + type_size * ((left + right)/2);
    int anchorid = (left + right) / 2;
    int i = left;
    int j = right;
    while (i < j) {
        while (compare(arr + i*type_size, anchor) && i < anchorid) i++;
        while (compare(anchor, arr + j*type_size) && j > anchorid) j--;
        if (i < j) {
            swag(arr+type_size*i, arr+type_size*j, type_size);
            if (i == anchorid) anchorid = j;
            else if (j == anchorid) anchorid = i;
        }
    }

    qsort(arr, left, anchorid - 1, sizeof(int), compare);
    qsort(arr, anchorid + 1, right, sizeof(int), compare);
}



int main()
{
    int arr[6] = {1, 3, 5, 7, 2, 4};
    qsort(arr, 0, 5, sizeof(int), compare);
    for (int i=0; i<6; i++){
        cout<<arr[i];
    }
}
