#include <iostream>

int main(int argc, char const *argv[])
{
	std::string s;
	int T;
	std::cin>>T;
	while(T--) {
		std::cin>>s;
        int ind = 0, count = 1, max = -1, maxi = 0;
        for(int i=0;i<s.size()-1;i++){
            if((s[i]+1 == s[i+1]) || (s[i] == 'a' && s[i+1] == 'z'))
                count++;
            else {
                // ind = i+1;
                count = 1;
            }
            if(max < count){
                max = count;
                maxi = i - count;
            }
        }
        for(int i=maxi;i<count;i++)
            std::cout<<s[i];
        std::cout<<std::endl<<count<<std::endl;
		s.clear();
	}
    return 0;
}
