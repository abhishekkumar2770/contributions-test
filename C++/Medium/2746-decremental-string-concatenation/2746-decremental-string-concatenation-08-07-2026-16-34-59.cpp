class Solution {
public:
    int dp[1001][26][26];

    int solve(vector<string>& words, int i, int first, int last) {
        if (i == words.size()) return 0;

        int &res = dp[i][first][last];
        if (res != -1) return res;

        string &w = words[i];
        int len = w.size();
        int f = w.front() - 'a';
        int l = w.back() - 'a';

        // Append to the right
        int cost1 = len - (last == f);
        cost1 += solve(words, i + 1, first, l);

        // Append to the left
        int cost2 = len - (l == first);
        cost2 += solve(words, i + 1, f, last);

        return res = min(cost1, cost2);
    }

    int minimizeConcatenatedLength(vector<string>& words) {
        memset(dp, -1, sizeof(dp));

        string &s = words[0];
        int first = s.front() - 'a';
        int last = s.back() - 'a';

        return s.size() + solve(words, 1, first, last);
    }
};