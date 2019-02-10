#include <iostream>

long long gcd(long long a, long long b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}

int main() {
    short T;
    long long N, K, count1, count2, mix, lcm, A, B;
    std::cin>>T;
    while(T--) {
        std::cin>>N>>A>>B>>K;
        count1 = N/A;           //Number of multiples of A upto N
        count2 = N/B;           //Number of multiples of B upto N
        lcm = (A*B)/gcd(A, B);
        mix = N/lcm;            //Number of multiples of A*B
        if((count1 + count2 - 2*mix) >= K)          //Total multiples of A or B but not of A and B upto N
            std::cout<<"Win"<<std::endl;
        else
            std::cout<<"Lose"<<std::endl;
    }
	return 0;
}