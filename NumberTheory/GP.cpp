#include <iostream>

float exponentiation(float x, int y) {
    float result = 1;
    while(y > 0){
        if(y&1)
            result *= x;
        x *= x;
        y >>= 1;
    }
    return result;
}

float GP(float a, float b, int n) {
    float q = b/a;
    float *arr = new float[n];
    *(arr + 0) = a;
    for(int i=1;i<n;i++)
        *(arr+i) = a*exponentiation(q, i);
    return int(*(arr+n-1));
}


int main(int argc, char const *argv[])
{
    std::cout<<GP(84, 87, 3)<<std::endl;
    return 0;
}
