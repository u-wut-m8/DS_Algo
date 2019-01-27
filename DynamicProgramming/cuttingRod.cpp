#include <iostream>
#include <vector>
#include <climits>

int cutRodDP(const std::vector<int>& prices, const int& size) {
    std::vector<int> revenue(size + 1);
    revenue[0] = 0;
    for(int i=1;i<=size;i++){
        int max_val = INT_MIN;
        for(int j=1;j<=i;j++){
            int temp = prices[j-1] + revenue[i-j];
            if(max_val < temp)
                max_val = temp;
        }
        revenue[i] = max_val;
    }
    return revenue[size];
}

int main() {
    std::cout<<cutRodDP(std::vector<int>({1, 5, 8, 9, 10, 17, 17, 20}), 8)<<std::endl;
    return 0;
}