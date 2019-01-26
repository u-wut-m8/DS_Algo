#include <iostream>

#define Maxn 10001
#define Mod 1000000007

/*Mod function to find modulo for -ve numbers also. */
inline long long mod(long long a, long long b) {
    a %= b;
    return a < 0 ? a+b : a;
}

long long inverse(long long x, long long p) {
    x = mod(x, p);
    if(x == 1)
        return 1;
    else
        return mod(1LL*(-p/x)*inverse(p%x, p), p);
}

int main(int argc, char const *argv[])
{
    long long fact[Maxn], ifact[Maxn], inv[Maxn];
    fact[0] = ifact[0] = 1;
    for(int i=1;i<Maxn;i++)
        fact[i] = 1LL*fact[i-1]*i%Mod;
    for(int i=1;i<Maxn;i++){
        inv[i] = inverse(i, Mod);
        ifact[i] = (1LL*ifact[i-1]*inv[i])%Mod;
    }
    int T, n, r;
    long long ans;
    std::cin>>T;
    while(T--) {
        std::cin>>n>>r;
        ans = (1LL*ifact[n-r]*ifact[r])%Mod;
        ans = (1LL*fact[n]*ans)%Mod;
        std::cout<<ans<<std::endl;
    }
    return 0;
}
