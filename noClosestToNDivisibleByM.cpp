#include <iostream>

int closestNumber(const int& n, const int& m) {
    int quotient = n/m;
    int num1 = m*quotient;
    int num2 = n*m > 0 ? m*(quotient+1) : m*(quotient-1);
    if (std::abs(n-num1) < std::abs(n-num2))
        return num1;
    else
        return num2;
}

int main(int argc, char const *argv[])
{
    std::cout<<closestNumber(13, 4)<<std::endl;
    std::cout<<closestNumber(-15, 6)<<std::endl;
    return 0;
}
