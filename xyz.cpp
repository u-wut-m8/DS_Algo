/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <iostream>
#include <map>

int main()
{
	//Write code here
	std::string s;
	std::map<char, char> m;
	m['A'] = 'T';
	m['T'] = 'A';
	m['C'] = 'G';
	m['G'] = 'C';
	std::cin>>s;
	for(int i=s.size()-1;i>=0;i--)
	    std::cout<<m[s[i]];
	return 0;
}