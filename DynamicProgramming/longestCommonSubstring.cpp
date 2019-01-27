#include <iostream>
#include <vector>

template <typename T>
inline T max(const T& a, const T& b) {
    return a > b ? a : b;
}

int lcs(std::string s1, std::string s2) {
    int n = s1.size(), m = s2.size();
    int max_val = -1;
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = 0;
            max_val = max(max_val, dp[i][j]);
        }
    return max_val;
}

int main() {
    std::cout<<lcs("DEADBEEF", "EATBEEF")<<std::endl;
    return 0;
}