#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

int findMinSwap(int *arr, const int& n){
    std::vector<std::pair<int, int>> v(n);
    /*Store initial ordering (value and indexes)*/
    for(int i=0;i<n;i++) {
        v[i].first = arr[i];
        v[i].second = i;
    }
    std::sort(v.begin(), v.end());                      //Sort the elements
    int ans = 0;
    for(int i=0;i<n;i++){
        /*If current index after sorting is same as initial index then don't swap.*/
        if(v[i].second == i)
            continue;
        else {
            /*Swap element with value at index of previous order.*/
            std::swap(v[i].first, v[v[i].second].first);
            std::swap(v[i].second, v[v[i].second].second);
        }
        /*If even after swapping correct element is not found keep on swapping the element at same index again.*/
        if(v[i].second != i)
            i--;
        ans++;              //Count each swap.
    }
    v.clear();
    return ans;
}

int main(int argc, char *argv[]) {
    int T, N, *arr;
    std::cin>>T;
    while(T--) {
        std::cin>>N;
        arr = new int[N];
        for(int i=0;i<N;i++)
            std::cin>>*(arr+i);
        std::cout<<findMinSwap(arr, N)<<std::endl;
        delete[] arr;
    }
    return 0;
}