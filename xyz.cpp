#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    std::map<std::string, int> mp;
	int T, N;
	std::string s, temp;
	std::vector<std::string> arr, count;
	std::cin>>T;
	while(T--){
		std::cin>>N;
		for(int i=0;i<N;i++){
			std::cin>>s;
			arr.push_back(s);
			mp[s]++;
		}
		temp = arr[0];
		for(std::map<std::string, int>::iterator it=mp.begin();it!=mp.end();++it)
			if(mp[temp] < it->second)
				temp = it->first;
		for(std::map<std::string, int>::iterator it=mp.begin();it!=mp.end();++it)
			if(it->second == mp[temp])
				count.push_back(it->first);
		if(count.size() == 1)
			std::cout<<count[0]<<" "<<mp[count[0]]<<std::endl;
		else {
			std::sort(count.begin(), count.end());
			std::cout<<count[0]<<" "<<mp[count[0]]<<std::endl;
		}
		count.clear();
		mp.clear();
		arr.clear();
	}
	return 0;
}