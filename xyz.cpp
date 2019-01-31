#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

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
		std::vector<long long> first(arr, arr+M), last(arr+M, arr+N);
	    for(int i=0;i<first.size();i++)
			std::cout<<first[i]<<" ";
		std::cout<<std::endl;
		for(int i=0;i<last.size();i++)
			std::cout<<last[i]<<" ";
		std::vector<long long> v(first.size()*last.size());
		for(int i=0;i<first.size();i++)
		
		std::cout<<std::endl;
	    delete[] arr;
	}
	return 0;
}