#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] ^ nums[i];
        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
        for (int i = 1; i <= n; i++) dp[i][1] = prefix[i];
        
        for (int j = 2; j <= k; j++) {
            for (int i = j; i <= n; i++) {
                for (int p = j - 1; p < i; p++) {
                    if (dp[p][j - 1] != INT_MAX) {
                        int cur = prefix[i] ^ prefix[p];
                        dp[i][j] = min(dp[i][j], max(dp[p][j - 1], cur));
                    }
                }
            }
        }
        return dp[n][k];
    }
};
