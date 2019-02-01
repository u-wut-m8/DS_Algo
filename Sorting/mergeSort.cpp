#include <iostream>

void merge(int *arr, int start, int mid, int end){
    int p = start, q = mid+1;
    int res[end-start+1], k = 0;
    for(int i=start;i<=end;i++)
        if(p > mid)
            res[k++] = arr[q++];
        else if(q > end)
            res[k++] = arr[p++];
        else if(arr[p] < arr[q])
            res[k++] = arr[p++];
        else
            res[k++] = arr[q++];
    for(int i=0;i<k;i++)
        arr[start++] = res[i];
}

void merge_sort(int *arr, int start, int end) {
    if(start < end) {
        int mid = (start + end)>>1;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid+1, end);    
        merge(arr, start, mid, end);
    }
}

int main(int argc, char *argv[]) {
    int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    merge_sort(a, 0, sizeof(a)/sizeof(a[0]));
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
        std::cout<<a[i]<<" ";
    std::cout<<std::endl;
    return 0;
}