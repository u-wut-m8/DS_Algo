#include <iostream>
#include <vector>

void primeFactors(int num) {
    while (!(num&1)) {
        std::cout<<2<<", ";
        num >>= 1;
    }

    for(int i=3;i*i<=num;i+=2)
        while(num%i == 0){
            std::cout<<i<<", ";
            num /= i;
        }
    
    if (num > 2)
        std::cout<<num;
    std::cout<<std::endl;
}

/*Efficient Prime Factorization*/
#define MAX 100001

int spf[MAX];
//Calculate smallest prime factor for every number till MAX, O(nloglogn)
void sieve() {                                  //Use modified sieve
    spf[1] = 1;
    for(int i=2;i<MAX;i++)
        if (i&1)
            spf[i] = i;                         //Initially mark SPF of all odd numbers as themselves
        else
            spf[i] = 2;                         //SPF of all even numbers is 2
    
    for(int i=3;i*i<MAX;i++)
        if(spf[i] == i)                         //Check if i is prime(only prime numbers can have SPF as themselves)
            for(int j=i*i;j<MAX;j+=i)           //Mark SPF of all numbers divisible by i as i
                if(spf[j] == j)
                    spf[j] = i;
}

//Returns prime factors by dividing the number with its SPF at every step, O(logn)
std::vector<int> efficientPrimeFactorization(int x){
    std::vector<int> temp;
    while(x != 1){
        temp.push_back(spf[x]);
        x /= spf[x];
    }
    return temp;
}

int main(int argc, char const *argv[])
{
    // primeFactors(315);
    sieve();
    std::vector<int> t = efficientPrimeFactorization(12246);
    for(int val : t)
        std::cout<<val<<", ";
    std::cout<<std::endl;
    return 0;
}
