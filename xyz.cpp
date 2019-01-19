#include <iostream>

void sieve(const int& num) {
    bool isPrime[num+1];
    for(int i=0;i<num;i++)
        *(isPrime + i) = true;
    *(isPrime + 0) = *(isPrime + 1) = false;
    for(int i=2;i*i<=num;i++)
        if(*(isPrime + i))
            for(int j=i*i;j<=num;j+=i)
                *(isPrime + j) = false;
    for(int i=0;i<=num;i++)
        if(*(isPrime + i))
            std::cout<<i<<" ";
    std::cout<<std::endl;
}

int main(int argc, char const *argv[])
{
    sieve(7507);
    return 0;
}
