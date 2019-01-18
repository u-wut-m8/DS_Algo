#include <iostream>

int fi(int num){
    int result = num;
    for(int i=2;i*i<=num;i++)
        if(num%i == 0){
            while(num%i == 0)
                num /= i;
            result -= (result/i);
        }
    if(num > 1)
        result -= (result/num);
    return result;
}

int main(){
    int N;
    std::cin>>N;
    std::cout<<fi(N)<<std::endl;
    return 0;
}