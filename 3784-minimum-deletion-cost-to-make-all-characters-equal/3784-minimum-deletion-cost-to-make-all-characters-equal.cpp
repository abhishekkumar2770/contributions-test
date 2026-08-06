class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<long long> keep(26, 0);
        long long total = 0;

        for (int i = 0; i < s.size(); i++) {
            total += cost[i];
            keep[s[i] - 'a'] += cost[i];
        }

        long long mx = 0;
        for (long long x : keep)
            mx = max(mx, x);

        return total - mx;
    }
};