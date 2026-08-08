class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n);

        for (auto &p : paths) {
            int u = p[0] - 1;
            int v = p[1] - 1;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            bool used[5] = {};

            // Mark flower types used by adjacent gardens
            for (int neighbor : graph[i]) {
                if (ans[neighbor] != 0) {
                    used[ans[neighbor]] = true;
                }
            }

            // Choose any available flower type
            for (int flower = 1; flower <= 4; flower++) {
                if (!used[flower]) {
                    ans[i] = flower;
                    break;
                }
            }
        }

        return ans;
    }
};