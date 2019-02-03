#include <iostream>
#include <iomanip>
#include <sstream>

template <typename T>
std::string to_string_with_precision(const T a_value, const int n=6){
    std::ostringstream out;
    out.precision(n);
    out<<std::fixed<<a_value;
    return out.str();
}

int main() {
    int T;
    long double N, D;
    std::string s;
    std::cin>>T;
    while(T--) {
        std::cin>>N>>D;
        s = to_string_with_precision(N/D, 100);
        std::cout<<s<<std::endl;
        s.clear();
    }
	return 0;
}