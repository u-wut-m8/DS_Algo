#include <iostream>

#define MAX 10000001

int spf[MAX] = {0};

void findSPF() {
    spf[1] = 1;
    for(int i=2;i<MAX;i++)
        if(i&1)
            spf[i] = i;
        else
            spf[i] = 2;
    for(int i=3;i*i<MAX;i++)
        if(spf[i] == i)
            for(int j=i*i;j<MAX;j+=i)
                if(spf[j] == j)
                    spf[j] = i;
}

int calculateNoOfFactors(int num) {
    if (num == 1)
        return 1;
    int ans = 1, exp = 1;
    int dup = spf[num];
    num /= spf[num];
    while(num != 1) {
        if(spf[num] == dup)
            exp++;
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
    findSPF();
    int arr[] = {10, 30, 100, 450, 987};
    for(int i=0;i<5;i++)
        std::cout<<calculateNoOfFactors(*(arr+i))<<std::endl;
    return 0;
}
