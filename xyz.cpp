#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<int> fib = {0, 1};
    for(int i=2;i<300;i++)
        fib.push_back((fib[i-1] + fib[i-2])%100);
    int T, N;
    std::cin>>T;
    while(T--) {
        std::cin>>N;
        std::cout<<fib[N%300]<<std::endl;
    }
    return 0;
}