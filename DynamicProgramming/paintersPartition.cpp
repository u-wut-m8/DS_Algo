#include <iostream>
#include <climits>

//Recursive solution
/*
int sum(const int *arr, const int& from, const int& to) {
    int ans = 0;
    for(int i=from;i<=to;i++)
        ans += arr[i];
    return ans;
}

int partitions(int *arr, const int& n, const int& k) {
    if(k == 1)
        return sum(arr, 0, n-1);
    if(n == 1)
        return arr[0];
    int best = INT_MAX;
    for(int i=1;i<=n;i++)
        best = std::min(best, std::max(partitions(arr, i, k-1), sum(arr, i, n-1)));
    return best;
}
*/

//DP solution
int sum(const int *arr, const int& from, const int& to) {
    int ans = 0;
    for(int i=from;i<=to;i++)
        ans += arr[i];
    return ans;
}

int findMax(int *arr, const int& n, const int& k) {
    int dp[k+1][n+1] = {0};
    //base case k = 1
    for(int i=1;i<=n;i++)
        dp[1][i] = sum(arr, 0, i-1);
    //n = 1
    for(int i=1;i<=k;i++)
        dp[i][1] = arr[0];
       for (int i = 2; i <= k; i++)  // 2 to n boards 
        for (int j = 2; j <= n; j++) { 
            // track minimum 
            int best = INT_MAX; 
            // i-1 th separator before position arr[p=1..j] 
            for (int p = 1; p <= j; p++)  
                best = std::min(best, std::max(dp[i - 1][p], sum(arr, p, j - 1)));
            dp[i][j] = best; 
        } 
    return dp[k][n];
}

int main(int argc, char* argv[]) {
    int T, K, N, *a;
    std::cin>>T;
    while(T--) {
        std::cin>>K>>N;
        a = new int[N];
        for(int i=0;i<N;i++)
            std::cin>>*(a+i);
        std::cout<<findMax(a, N, K)<<std::endl;
        delete[] a;
    }
    return 0;
}