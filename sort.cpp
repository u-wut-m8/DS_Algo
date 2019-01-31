#include <iostream>

template <typename T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

void selectionSort(int *arr, const int& n) {
    int min;
    for(int i=0;i<n-1;i++){
        min = i;
        for(int j=i+1;j<n;j++)
            if(arr[min] > arr[j])
                min = j;
        swap(arr[min], arr[i]);
    }
    for(int i=0;i<n;i++)
        std::cout<<arr[i]<<" ";
    std::cout<<std::endl;
}

void bubbleSort(int *arr, const int& n) {
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1-i;j++)
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
    for(int i=0;i<n;i++)
        std::cout<<arr[i]<<" ";
    std::cout<<std::endl;
}

int main(int argc, char *argv[]) {
    int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    selectionSort(a, 10);
    int a1[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    bubbleSort(a1, 10);
    return 0;
}