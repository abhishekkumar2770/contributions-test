class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, vector<int>> pos;

        for (int i = 0; i < n; i++)
            pos[arr[i]].push_back(i);

        vector<long long> ans(n, 0);

        for (auto &it : pos) {
            vector<int>& v = it.second;
            int m = v.size();

            vector<long long> prefix(m + 1, 0);

            for (int i = 0; i < m; i++)
                prefix[i + 1] = prefix[i] + v[i];

            for (int i = 0; i < m; i++) {
                long long left = 1LL * v[i] * i - prefix[i];

                long long right =
                    (prefix[m] - prefix[i + 1]) -
                    1LL * v[i] * (m - i - 1);

                ans[v[i]] = left + right;
            }
        }

        return ans;
    }
};