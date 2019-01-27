#include <iostream>
#include <vector>

int knapsack(const std::vector<int>& values, const std::vector<int>& weights, const int& n, const int& w) {
    std::vector<std::vector<int>> R(n+1, std::vector<int>(w+1, 0));           //R[i][j] = maximum profit when using the first i elements having capacity of j.
    for(int i=1;i<=n;i++)
        for(int j=1;j<=w;j++)
            if(j-weights[i]>=0 && ((values[i-1] + R[i-1][j-weights[i-1]]) > R[i-1][j]))
                R[i][j] = values[i-1] + R[i-1][j-weights[i-1]];               //Maximum value obtained by picking current element's value.
            else
                R[i][j] = R[i-1][j];                                          //Maximum value obtained without picking current element's value.
    return R[n][w];
}

int main() {
    std::cout<<knapsack(std::vector<int>({10, 40, 30, 50}), std::vector<int>({5, 4, 6, 3}), 4, 9)<<std::endl;
    return 0;
}