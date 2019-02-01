#include <iostream>
#include <algorithm>

int partition(int *res, int start, int end){
    int i = start+1;
    int pivot = res[start];
    for(int j=start+1;j<=end;j++)
        if(res[j] < pivot){
            std::swap(res[j], res[i]);
            i++;
        }
    std::swap(res[start], res[i-1]);
    return i-1;
}

void quick_sort(int *arr, int start, int end) {
    if(start < end){
        int piv = partition(arr, start, end);
        quick_sort(arr, start, piv-1);
        quick_sort(arr, piv+1, end);
    }
}

int main(int argc, char *argv[]) {
    int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    quick_sort(a, 0, 9);
    for(int i=0;i<10;i++)
        std::cout<<*(a+i)<<' ';
    std::cout<<std::endl;
    return 0;
}