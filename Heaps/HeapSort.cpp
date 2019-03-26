#include <iostream>

// template <typename T>
// void swap(T& a, T& b){
//     a ^= b;
//     b ^= a;
//     a ^= b;
// }

// class MinHeap {
// private:
//     int* heapArr;
//     int capacity;
//     int currentSize;
// public:
//     MinHeap(const int& cap){
//         capacity = cap;
//         heapArr = new int[capacity];
//     }
//     inline int parent(const int& index) const {
//         return (index-1)>>1;
//     }
//     inline int left(const int& index) const {
//         return index<<1 + 1;
//     }
//     inline int right(const int& index) const {
//         return index<<1 + 2;
//     }
//     void percUp(int);
//     void insert(const int&);
//     inline int minChild(const int&) const;
//     void percDown(int);
//     void buildHeap(int*, const int&);
//     void heapSort();
//     ~MinHeap() {
//         delete[] heapArr;
//     }
// };
// void MinHeap::percUp(int index) {
//     while(index>>1 >= 0){
//         if(*(heapArr + index) < *(heapArr + parent(index)))
//             swap(*(heapArr+index), *(heapArr + parent(index)));
//         index = parent(index);
//     }
// }
// void MinHeap::insert(const int& item){
//     if(capacity == currentSize){
//         std::cout<<"Heap overflow!"<<std::endl;
//         return;
//     }
//     heapArr[currentSize] = item;
//     currentSize++;
//     percUp(currentSize-1);
// }
// inline int MinHeap::minChild(const int& index) const {
//     return right(index) > currentSize ? left(index) : right(index) < left(index) ? right(index) : left(index);
// }
// void MinHeap::percDown(int index) {
//     int min_child;
//     while(left(index) <= currentSize){
//         min_child = minChild(index);
//         if(*(heapArr + index) > *(heapArr + min_child))
//             swap(*(heapArr + index), *(heapArr + min_child));
//         index = min_child;
//     }
// }
// void MinHeap::buildHeap(int* arr, const int& size) {
//     int index = (size-1)>>1;
//     currentSize = size;
//     for(int i=0;i<size;i++)
//         *(heapArr + i) = *(arr + i);
//     while(index >= 0) {
//         percDown(index);
//         index--;
//     }
// }
// void MinHeap::heapSort() {
//     int heap_size = currentSize;
//     buildHeap(heapArr, heap_size);
//     for(int i=currentSize-1;i>=2;i--){
//         swap(heapArr[0], heapArr[i]);
//         heap_size--;
//         percDown(0);
//     }
// }
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
    if (largest != i) 
    { 
        std::swap(arr[i], arr[largest]); 
        heapify(arr, n, largest); 
    } 
} 
void heapSort(int arr[], int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
    for (int i=n-1; i>=0; i--) 
    { 
        std::swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    } 
} 

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T, N, K, *a;
    std::cin>>T;
    while(T--) {
        std::cin>>N>>K;
        a = new int[N];
        for(int i=0;i<N;i++)
            std::cin>>*(a + i);
        heapSort(a, N);
        for(int i=N-1;i>=N-K;i--)
            std::cout<<*(a + i)<<' ';
        std::cout<<std::endl;
        delete[] a;
    }
    return 0;
}