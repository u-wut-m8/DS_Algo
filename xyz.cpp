/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <iostream>
#include <cctype>

int main()
{
	//Write code here
	std::string s;
	std::cin>>s;
	int dc = 0, nc = 0;
	for(int i=0;i<s.size();i++){
	    if(s.at(i) == '.')
	        dc++;
	    else if(isdigit(s.at(i)))
	        nc++;
	    if(dc == 2)
	        break;
	    if(isalpha(s.at(i))){
	        std::cout<<"This input is of type string.";
	        return 0;
	    }
	}
	if(dc == 1)
	    std::cout<<"This input is of type Float.";
	else if(nc == s.size() || (nc == s.size()-1 && s[0] == '-'))
	    std::cout<<"This input is of type Integer.";
	else
	    std::cout<<"This is something else.";
	return 0;
}