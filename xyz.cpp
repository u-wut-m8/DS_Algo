#include <iostream>

int solve(std::string p, std::string s) {
	if (s.size() % p.size() != 0)
		return 0;
	if (p == s)
		return 1;
	while(p.size() <= s.size()){
		p += p;
		if(p == s)
			return 1;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	std::string p, s;
	int T;
	std::cin>>T;
	while(T--) {
		std::cin>>p>>s;
		std::cout<<solve(p, s)<<std::endl;
		s.clear();
		p.clear();
	}
    return 0;
}
