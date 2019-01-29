#include <iostream>
#include <map>

int main() {
	std::string s;
	int T, e, o;
	std::map<char, int> mp;
	std::cin>>T;
	while(T--) {
		std::cin>>s;
		for(std::string::iterator it=s.begin();it!=s.end();++it)
			mp[*it]++;
		e = o = 0;
		for(std::map<char, int>::iterator it=mp.begin();it!=mp.end();++it)
			(*it).second&1 ? o++ : e++;
		if((s.size()&1 && o == 1) || (!(s.size()&1) && o == 0))
			std::cout<<"Yes"<<std::endl;
		else
			std::cout<<"No"<<std::endl;
		mp.clear();
	}
	return 0;
}