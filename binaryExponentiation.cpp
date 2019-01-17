#include <iostream>

#define m 1000000007

long long iterative(long long a, long long b) {
    long long result = 1;
    while (b > 0){
        if (b&1)
            result = (result*a)%m;
        a = (a*a)%m;
        b >>= 1;
    }
    return result;
}

long long recursive(long long a, long long b) {
    if(b == 0)
        return 1;
    else if(b&1)
        return (a*recursive((a*a)%m, (b-1)/2))%m;
    else
        return recursive((a*a)%m, b/2);
}

int main() {
    std::cout<<(iterative(2, 11) == 1<<11)<<std::endl<<recursive(5, 3)<<std::endl;
    return 0;
}