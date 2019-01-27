#include <iostream>
#include <vector>

template<typename T>
inline int max(const T& a, const T& b) {
    return a > b ? a : b;
}
template<typename T>
inline int min(const T& a, const T& b) {
    return a < b ? a : b;
}

int stockBuySellDP(const std::vector<int>& shares, const int& size) {
    std::vector<int> profit(size);
    profit[0] = 0;
    for(int i=1;i<size;i++) {
        profit[i] = profit[i-1];
        for(int j=0;j<=i;j++)
            profit[i] = max(profit[i], shares[i] - shares[j]);
    }
    return profit[size - 1];
}

int optimized(const std::vector<int>& shares, const int& size) {
    std::vector<int> profit(size);
    profit[0] = 0;
    int min_val = shares[0];
    for(int i=1;i<size;i++) {
        min_val = min(min_val, shares[i]);
        profit[i] = max(profit[i-1], shares[i] - min_val);
    }
    return profit[size - 1];
}

int main() {
    std::cout<<stockBuySellDP(std::vector<int>({7, 1, 5, 4, 6, 4}), 6)<<std::endl;
    std::cout<<stockBuySellDP(std::vector<int>({7, 6, 4, 3, 1}), 5)<<std::endl;
    std::cout<<optimized(std::vector<int>({7, 1, 5, 4, 6, 4}), 6)<<std::endl;
    std::cout<<optimized(std::vector<int>({7, 6, 4, 3, 1}), 5)<<std::endl;
    return 0;
}