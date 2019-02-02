#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

inline bool comparator(const std::pair<short, short>& a, const std::pair<short, short>& b){
    if(a.second == b.second)
        return a.first<b.first;
    else
        return a.second>b.second;
}

int main(int argc, char const *argv[])
{
	short T, N, temp;
    std::map<short, short> mp;
	std::cin>>T;
	while(T--) {
        std::cin>>N;
        for(int i=0;i<N;i++){
            std::cin>>temp;
            mp[temp]++;
        }
        std::vector<std::pair<short, short>> v(mp.begin(), mp.end());
        std::sort(v.begin(), v.end(), comparator);
        for(std::vector<std::pair<short, short>>::iterator it=v.begin();it!=v.end();++it)
            for(int i=0;i<(*it).second;i++)
                std::cout<<(*it).first<<" ";
        std::cout<<std::endl;
        mp.clear();
	}
    return 0;
}
