#include <iostream>
#include <vector>

template<typename T>
inline T max(const T& a, const T& b) {
    return a > b ? a : b;
}

int lcs(const std::string& s1, const std::string& s2) {
    int m = s1.size(), n = s2.size();
    std::vector<std::vector<int>> C(m+1, std::vector<int>(n+1, 0));
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(s1[i-1] == s2[j-1])
                C[i][j] = C[i-1][j-1] + 1;
            else
                C[i][j] = C[i-1][j], C[i][j-1];
    return C[m][n];
}

int main() {
    std::cout<<lcs("ABACBDAB", "BDCABA")<<std::endl;
    return 0;
}