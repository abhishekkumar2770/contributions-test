class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> pre(n, 0);

        for (auto &e : relations)
            pre[e[1] - 1] |= (1 << (e[0] - 1));

        int N = 1 << n;
        vector<int> dp(N, 1e9);
        dp[0] = 0;

        for (int mask = 0; mask < N; mask++) {
            if (dp[mask] == 1e9) continue;

            int avail = 0;

            // Courses whose prerequisites are satisfied
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i)) && (pre[i] & mask) == pre[i])
                    avail |= (1 << i);
            }

            if (__builtin_popcount(avail) <= k) {
                dp[mask | avail] = min(dp[mask | avail], dp[mask] + 1);
            } else {
                // Enumerate subsets of size k
                for (int sub = avail; sub; sub = (sub - 1) & avail) {
                    if (__builtin_popcount(sub) == k)
                        dp[mask | sub] = min(dp[mask | sub], dp[mask] + 1);
                }
            }
        }

        return dp[N - 1];
    }
};