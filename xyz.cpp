#include <iostream>

int main() {
	int T;
	std::string s1, s2;
	std::cin>>T;
	while(T--) {
		std::cin>>s1>>s2;
		int i = 0;
		if(s1.size() > s2.size()){
			for(i=0;i<s2.size();i++)
				std::cout<<s1[i]<<s2[i];
			for(int k=i;k<s1.size();k++)
				std::cout<<s1[k];
		}else if(s1.size() < s2.size()){
			for(i=0;i<s1.size();i++)
				std::cout<<s1[i]<<s2[i];
			for(int k=i;k<s2.size();k++)
				std::cout<<s2[k];
		} else 
			for(int i=0;i<s2.size();i++)
				std::cout<<(s1+s2)[i]<<(s1+s2)[i+s2.size()];
		std::cout<<std::endl;
	}
	return 0;
}