#include <iostream>

void solve(int num) {
    bool isPrime[num>>1];
    for(int i=0;i<sizeof(isPrime);i++)
        isPrime[i] = false;
    // isPrime[0] = false;
    // isPrime[1] = false;
    for(int i=3;i*i<num;i+=2)
        if(isPrime[i>>1] == false)
            for(int j=i*i;j<num;j+=(i<<1))
                isPrime[j>>1] = true;
    unsigned long long sum = 2;
    for(int i=3;i<num;i+=2)
        if(isPrime[i>>1] == false)
            sum += i;
    std::cout<<sum<<std::endl;
}

int main() {
    int T, N;
    std::cin>>T;
    while(T--) {
        std::cin>>N;
        solve(N+1);
    }
	return 0;
}