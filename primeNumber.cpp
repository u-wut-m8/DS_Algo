#include <iostream>
#include <algorithm>

void findPrime(const long& num1, const long& num2) {
    for(long i=num1;i<=num2;i++){
        short flag = 0;
        for(long j=2;j*j<i;j++)
            if(i%j == 0){
                flag = 1;
                break;
            }
        if (!flag)
            std::cout<<i<<std::endl;
    }
}

void sieve(long num) {
    bool isPrime[num+1];
    for(long i=0;i<=num;i++)
        isPrime[i] = true;
    isPrime[0] = false;
    isPrime[1] = false;
    for(long i=2;i*i<=num;i++)
        if(isPrime[i] == true)
            for(long j=i*i;j<=num;j+=i)
                isPrime[j] = false;

    for(long i=0;i<=num;i++)
        if(isPrime[i] == true)
            std::cout<<i<<std::endl;
}

void rangeSieve(int l, int r) {
    bool isPrime[r-l+1];
    for(int i=0;i<r-l;i++)
        isPrime[i] = true;
    for(long long i=2;(i*i)<=r;i++)
        for(long long j=std::max((i*i), ((l+(i-1))/i) * i);j<=r;j+=i)
            isPrime[j-l] = false;
    for(long long i=std::max(l, 2);i<=r;i++)
        if(isPrime[i-l])
            std::cout<<i<<std::endl;
}

int main(int argc, char const *argv[]) 
{
    // findPrime(50, 80);
    rangeSieve(50, 80);
    return 0;
}