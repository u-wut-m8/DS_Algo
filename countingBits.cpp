#include <iostream>

long countSetBits(int num) {
    long count = 0;
    while(num > 0) {
        count += num&1;
        num >>= 1;
    }
    return count;
}

/*Count number of bits to be flipped to convert A to B.*/
inline long flipCount(const long& a, const long& b){
    return countSetBits(a^b);
}

int main(int argc, char const *argv[])
{
    std::cout<<countSetBits(12)<<std::endl;
    std::cout<<__builtin_popcount(15)<<std::endl;
    return 0;
}
