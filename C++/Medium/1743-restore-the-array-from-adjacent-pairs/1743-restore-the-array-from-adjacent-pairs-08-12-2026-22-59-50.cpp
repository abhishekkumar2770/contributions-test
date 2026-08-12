class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;

        // Build graph
        for (auto &p : adjacentPairs) {
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }

        // Find an endpoint
        int start = 0;
        for (auto &it : graph) {
            if (it.second.size() == 1) {
                start = it.first;
                break;
            }
        }

        vector<int> ans;
        int prev = INT_MAX;
        int curr = start;

        while (true) {
            ans.push_back(curr);

            int next = INT_MAX;

            for (int x : graph[curr]) {
                if (x != prev) {
                    next = x;
                    break;
                }
            }

            if (next == INT_MAX)
                break;

            prev = curr;
            curr = next;
        }

        return ans;
    }
};