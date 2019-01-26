#include <iostream>
#include <algorithm>
#include <climits>

int main() {
	//code
	int T, N, M;
	long long *arr, min;
	std::cin>>T;
	while(T--) {
	    std::cin>>N;
	    min = INT_MAX;
	    arr = new long long[N];
	    for(int i=0;i<N;i++)
	        std::cin>>*(arr + i);
	    std::cin>>M;
	    std::sort(arr, arr+N);
	    for(int i=0;i<N-M+1;i++)
	        if(std::abs(arr[i] - arr[i+M-1]) < min)
	            min = std::abs(arr[i] - arr[i+M-1]);
	    std::cout<<min<<std::endl;
	    delete[] arr;
	}
	return 0;
}