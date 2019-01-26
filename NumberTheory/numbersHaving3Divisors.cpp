#include <iostream>

void sieve(int *arr, int num){
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2;i<num;i++)
        if(i&1)
            arr[i] = i;
        else
            arr[i] = 2;
    for(int i=3;i*i<num;i++)
        if(arr[i] == i)
            for(int j=i*i;j<num;j+=i)
                if(arr[j] == j)
                    arr[j] = i;
}

int numberOfFactors(int num, int *spf) {
    if(num == 1)
        return 1;
    int ans = 1;
    int exp = 1;
    int dup = spf[num];
    num /= spf[num];
    while(num != 1) {
        if (spf[num] == dup)
            exp += 1;
        else {
            dup = spf[num];
            ans *= (exp + 1);
            exp = 1;
        }
        num /= spf[num];
    }
    ans *= (exp + 1);
    return ans;
}

int main(int argc, char const *argv[])
{
    int T, N, *spf, count;
    std::cin>>T;
    while(T--) {
        std::cin>>N;
        spf = new int[N+1];
        sieve(spf, N+1);
        count = 0;
        for(int i=1;i<=N;i++)
            if(numberOfFactors(i, spf) == 3)
                count++;
        std::cout<<count<<std::endl;
        delete[] spf;
    }
    return 0;
}
