#include <iostream>

inline void trim(std::string& str) {
	str.erase(0, str.find_first_not_of(' '));
	str.erase(str.find_last_not_of(' ') + 1);
}

int main() {
	int T, K, c;
	std::string s;
	std::cin>>T;
	while(T--) {
		c = 0;
		std::cin.ignore();
		std::getline(std::cin, s, '\n');
		std::cin.clear();
		std::cin>>K;
		trim(s);
		for(int i=0;i<s.size();i++)
			if(s[i] == ' ')
				c++;
		K = s.size();
		s.resize(s.size() + c*2, ' ');
		for(int i=K-1;i>=0;i--)
			if(s[i] == ' '){
				s[i+(c*2)-1] = ' ';
				s[i+(c*2)-2] = ' ';
				s[i+(c*2)] = ' ';
				c--;
			} else
				s[i+(c*2)] = s[i];
		for(int i=0;i<s.size();i++)
			if(s[i] == ' '){
				s[i] = '%';
				s[i+1] = '2';
				s[i+2] = '0';
				i += 2;
			}
		std::cout<<s<<std::endl;
	}
	return 0;
}