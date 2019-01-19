#include <iostream>
#include <cmath>

int main(int argc, char const *argv[])
{
    int T, *arr;
    long long N, count;
    std::cin>>T;
    while(T--) {
        std::cin>>N;
        // arr = new int[N];
        // for(long long i=0;i<N;i++)
        //     *(arr+i) = 1;
        // count = 2;
        // for(long long i=2;i<=N;i++){
        //     for(long long j=i-1;j<N;j+=i)
        //         if(arr[j-1])
        //             arr[j-1] = 0;
        //         else
        //             arr[j-1] = 1;
        // }
        // count = 0;
        // for(long long i=0;i<N;i++)
        //     if(arr[i])
        //         count++;
        // std::cout<<count<<std::endl;
        // delete[] arr;
        std::cout<<std::floor(std::sqrt(N))<<std::endl;
    }
    return 0;
}
