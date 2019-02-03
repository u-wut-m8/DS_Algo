#include <iostream>
#define MAX 1000001
bool isPrime[MAX];

void solve() {
    for(int i=0;i<MAX;i++)
        isPrime[i] = true;
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i=2;i*i<=MAX;i++)
        if(isPrime[i])
            for(int j=i*i;j<MAX;j+=i)
                isPrime[j] = false;
    for(int i=2;i<MAX;i++)
        if(isPrime[i])
            std::cout<<i<<" ";
    std::cout<<std::endl;
}

int main() {
    int T, N;
    std::cin>>T;
    while(T--) {
        std::cin>>N;
        solve();
    }
	return 0;
}