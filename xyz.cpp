#include <iostream>
#include <map>

int main() {
	int T, N, M, k;
	std::map<int, int> mp;
	std::cin>>T;
	while(T--) {
	    std::cin>>N>>M;
		for(int i=0;i<N;i++){
			std::cin>>k;
			mp[k]++;
		}
		for(int i=0;i<M;i++){
			std::cin>>k;
			if(mp[k] != 0){
				int j = mp[k];
				while(j--)
					std::cout<<k<<" ";
				mp[k] = -1;
			}
		}
		for(std::map<int, int>::iterator it=mp.begin();it!=mp.end();++it)
			if((*it).second != -1)
				std::cout<<(*it).first<<" ";
		std::cout<<std::endl;
		mp.clear();
	}
	return 0;
}