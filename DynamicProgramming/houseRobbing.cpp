#include <iostream>
#include <vector>

template<typename T>
inline T max(const T& a, const T& b) {
    return (a > b) ? a : b;
}

int houseRobDP(const std::vector<int>& loots, const int& size) {
    std::vector<int> revenue(size);
    revenue[0] = loots[0];
    revenue[1] = max(loots[0], loots[1]);
    for(int i=2;i<size;i++){
        // revenue[i] = revenue[i-1];
        // for(int j=0;j<=i-2;j++)
        //     revenue[i] = max(revenue[i], loots[i] + revenue[j]);
        revenue[i] = max(revenue[i-1], loots[i] + revenue[i-2]);
    }
    return revenue[size - 1];
}

int main() {
    std::cout<<houseRobDP(std::vector<int>({1, 2, 3, 4, 5}), 5)<<std::endl;
    return 0;
}