#include <iostream>
#include <utility>
#include <map>

int main() {
	//code
	int T, N, *arr;
	std::multimap<int, std::pair<int, int>> mp;
	std::cin>>T;
	while(T--) {
	    std::cin>>N;
		arr = new int[N];
		for(int i=0;i<N;i++)
			std::cin>>*(arr+i);
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				mp.insert(std::make_pair(arr[i]+arr[j]), std::make_pair(arr[i], arr[j]));
		for(int i=0;i<mp.size();i++)
			// std::cout<<mp[i].first<<" "<<mp[i].second<<std::endl;
			std::cout<<mp[i].first<<" "<<std::pair<int, int>(mp[i].second).first<<std::endl;
		std::cout<<std::endl;
		mp.clear();
	    delete[] arr;
	}
	return 0;
}