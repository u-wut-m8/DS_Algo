#include <iostream>

int lcm(const int& a, const int& b){
    int max = a > b ? a : b;
    int min = max == a ? b : a;
    for(int i=max;;i+=max)
        if(i%min == 0)
            return i;
}

int gcd(const int& a, const int& b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a%b);
}

inline int efficientLCM(const int& a, const int& b) {
    return (a*b)/gcd(a, b);
}

int multiGCD(int *arr, int n) {
    int result = *(arr + 0);
    for(int i=1;i<n;i++)
        result = gcd(*(arr + i), result);
    return result;
}

long long multiLCM(int *arr, int n) {
    long long result = *(arr + 0);
    for(int i=1;i<n;i++)
        result = (*(arr+i)*result)/gcd(*(arr+i), result);
    return result;
}

int main(int argc, char const *argv[])
{
    std::cout<<lcm(5, 7)<<" "<<gcd(5, 7)<<std::endl;
    std::cout<<lcm(16, 10)<<" "<<gcd(16, 10)<<std::endl;
    std::cout<<efficientLCM(15, 60)<<" "<<gcd(15, 60)<<std::endl;
    int a[] = {2, 7, 3, 9, 4};
    std::cout<<multiLCM(a, 5)<<" "<<multiGCD(a, 5)<<std::endl;
    return 0;
}
