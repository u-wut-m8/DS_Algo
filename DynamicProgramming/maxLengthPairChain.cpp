#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

template<typename T>
inline int max(const T& a, const T& b) {
    return a > b ? a : b;
}

bool comparator(const std::pair<int, int>& a, const std::pair<int, int>& b){
    return a.second < b.first ? 0 : 1;
}

int findLongestChain(const std::vector<std::pair<int, int>>& pairs) {
    std::vector<int> dp(pairs.size());
    std::sort(pairs.begin(), pairs.end(), comparator);
    dp[0] = 1;
    for(int i=1;i<pairs.size();i++) {
        dp[i] = dp[i-1];
        for(int j=i-1;j>=0;j--)
            if(pairs[j].first < pairs[i].second)
                dp[i] = max(dp[i], dp[j] + 1);                
    }
    return dp[pairs.size()-1];
}

int main() {
    std::cout<<findLongestChain({std::pair<int, int>(1, 2), std::pair<int, int>(2, 3), std::pair<int, int>(3, 4)})<<std::endl;
    return 0;
}