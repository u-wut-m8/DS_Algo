#include <iostream>

int main(int argc, char const *argv[])
{
    int T, M, N, sum;
    std::cin>>T;
    while(T--) {
        std::cin>>M>>N;
        sum = 0;
        while(M>0 && N>0)
            sum += M--*N--;
        std::cout<<sum<<std::endl;
    }
    return 0;
}
