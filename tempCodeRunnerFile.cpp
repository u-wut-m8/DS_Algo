#include <iostream>
#include <vector>
#include <utility>

int main() {
	//code
	int *arr, T, N, K;
	std::vector<std::pair<int, int>> v;
	std::cin>>T;
	while(T--) {
	    std::cin>>N;
	    arr = new int[N];
	    for(int i=0;i<N;i++)
	        std::cin>>*(arr+i);
	    std::cin>>K;
	    for(int i=0, j=N-1;i<j;)
	        if(arr[i]+arr[j] == K){
				v.push_back(std::make_pair(arr[i], arr[j]));
	            i++;
	            j--;
	        }else if(arr[i]+arr[j]<K)
	            i++;
	        else
	            j--;
	    for(int i=0;i<v.size();i++)
	        std::cout<<v[i].first<<" "<<v[i].second<<" "<<K<<std::endl;
		v.clear();
	}
	return 0;
}