#include <iostream>
// #include <climits>

#define MAX 50000

int multiply(int n, int *arr, int res_size){
    int carry = 0;
    for(int i=0;i<res_size;i++){
        int prod = arr[i]*n + carry;
        arr[i] = prod%10;
        carry = prod/10;
    }
    while(carry){
        arr[res_size] = carry%10;
        carry /= 10;
        res_size++;
    }
    return res_size;
}

void factorial(int num){
    int res[MAX];
    res[0] = 1;
    int res_size = 1;
    for(int i=2; i<=num; i++)
        res_size = multiply(i, res, res_size);
    for(int i=res_size;i>=0;i--)
        std::cout<<*(res + i);
    std::cout<<std::endl;
}

int main(int argc, char const *argv[])
{
    factorial(5000);
    return 0;
}
