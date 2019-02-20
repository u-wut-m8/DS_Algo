#include <iostream>

int main(int argc, char* argv[]) {
    int T, N, K, *arr, sum, c, b;
    bool flag;
    std::cin>>T;
    while(T--){
        std::cin>>N>>K;
        arr = new int[N];
        for(int i=0;i<N;i++)
            std::cin>>*(arr+i);
        sum = c = b = 0;
        sum = arr[0];
        flag = true;
        while(sum != K){
            if(sum > K)
                sum -= arr[c++];
            else
                sum += arr[++b];
            if(c >= N || b >= N){
                flag = false;
                break;
            }
        }
        !flag ? std::cout<<-1<<std::endl : std::cout<<c+1<<' '<<b+1<<std::endl;
        delete[] arr;
    }
    return 0;
}