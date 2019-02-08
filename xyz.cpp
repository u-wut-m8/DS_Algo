#include <iostream>
#include <map>
#include <set>

void permutation(std::string str, const int& l, const int& r, std::set<std::string>& st){
	if(l == r)
		st.insert(str);
	else
		for(int i=l;i<=r;i++){
			std::swap(str[i], str[l]);
			permutation(str, l+1, r, st);
			std::swap(str[i], str[l]);
		}
}

int main(int argc, char* argv[]) {
	int T, N, temp;
	std::string s;
	std::map<int, std::string> mp = {std::make_pair(0, ""), std::make_pair(1, ""), std::make_pair(2, "abc"), std::make_pair(3, "def"), std::make_pair(4, "ghi"), std::make_pair(5, "jkl"), std::make_pair(6, "mno"), std::make_pair(7, "pqrs"), std::make_pair(8, "tuv"), std::make_pair(9, "wxyz")};
	std::cin>>T;
	std::set<std::string> st;
	while(T--) {
		std::cin>>N;
		s = "";
		for(int i=0;i<N;i++){
			std::cin>>temp;
			s += mp[temp];
		}
		permutation(s, 0, s.size()-1, st);
		for(std::set<std::string>::iterator it=st.begin();it!=st.end();++it)
			if((*it).size() == 3)
				std::cout<<(*it)<<' ';
		std::cout<<std::endl;
		st.clear();
	}
	return 0;
}