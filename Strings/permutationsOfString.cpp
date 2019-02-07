#include <iostream>
#include <set>

void permutation(std::string s, const int& l, const int& r, std::set<std::string>& st) {
    if(l == r)
        st.insert(s);
    else
        for(int i=l;i<=r;i++){
            std::swap(s[l], s[i]);
            permutation(s, l+1, r, st);
            std::swap(s[l], s[i]);
        }
}

int main(int argc, char *argv[]) {
    int T;
    std::string str;
    std::set<std::string> s;
    std::cin>>T;
    while(T--) {
        std::cin>>str;
        permutation(str, 0, str.size()-1, s);
        for(std::set<std::string>::iterator it=s.begin();it!=s.end();++it)
            std::cout<<(*it)<<" ";
        std::cout<<std::endl;
        s.clear();
    }
    return 0;
}