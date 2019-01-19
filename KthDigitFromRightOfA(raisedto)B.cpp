#include <iostream>

long long exponentiation(long long x, long long y) {
    long long result = 1;
    while(y > 0){
        if(y&1)
            result *= x;
        x *= x;
        y >>= 1;
    }
    return result;
}

long long ans(long long num, int k) {
    while(--k > 0)
        num /= 10;
    return num%10;
}

int main(int argc, char const *argv[])
{
    std::string s = std::to_string(exponentiation(3, 3));
    std::cout<<s.at(s.size()-1)<<std::endl;
    std::cout<<ans(exponentiation(15, 11), 8)<<std::endl;
    return 0;
}
