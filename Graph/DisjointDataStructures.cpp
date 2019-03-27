/*
    https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/tutorial/
*/

#include <iostream>
#include <algorithm>
#include <vector>

//Naive approach:
//Takes O(N^2) for N elements
// inline void initialize(int* arr, const int& size) {
//     for(int i=0;i<size;i++)
//         *(arr+i) = i;
// }

// inline bool find(int* arr, const int& A, const int& B) {
//     return *(arr + A) == *(arr + B);
// }

// void set_union(int* arr, const int& size, const int& A, const int& B) {
//     int temp = *(arr+A);
//     for(int i=0;i<size;i++)
//         if(*(arr+i) == temp)
//             *(arr+i) = *(arr+B);
// }

int root(int* arr, int i){
    while(*(arr+i) != i)
        i = *(arr+i);
    return i;
}

int union_set(int* arr, const int& A, const int& B){
    int root_A = root(arr, A);
    int root_B = root(arr, B);
    arr[root_A] = root_B;
}

inline bool find(int* arr, const int& A, const int& B) {
    return root(arr, A) == root(arr, B);
}

void efficient_initialize(int* arr, int* size, const int& n) {
    for(int i=0;i<n;i++){
        *(arr+i) = i;
        *(size+i) = 1;
    }
}

void efficient_union(int* arr, int* size, const int& A, const int& B) {
    int root_A = root(arr, A);
    int root_B = root(arr, B);
    if(size[root_A] < size[root_B]) {
        arr[root_A] = arr[root_B];
        size[root_B] += size[root_A];
        size[root_A] = 0;
    } else {
        arr[root_B] = arr[root_A];
        size[root_A] += size[root_B];
        size[root_B] = 0;
    }
}

int efficient_root(int* arr, int i) {
    while(arr[i] != i) {
        arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}

int main(int argc, char* argv[]) {
    int N, M, X, Y;
    int *nodes, *size;
    std::vector<int> temp;
    std::cin>>N>>M;
    nodes = new int[N];
    size = new int[N];
    efficient_initialize(nodes, size, N);
    while(M--) {
        std::cin>>X>>Y;
        efficient_union(nodes, size, X, Y);
        temp = std::vector<int>{size, size+N};
        std::sort(temp.begin(), temp.end());
        for(int i=0;i<N;i++)
            if(temp[i])
                std::cout<<temp[i]<<' ';
        std::cout<<std::endl;
        temp.clear();
    }
    delete[] nodes;
    delete[] size;
    return 0;
}