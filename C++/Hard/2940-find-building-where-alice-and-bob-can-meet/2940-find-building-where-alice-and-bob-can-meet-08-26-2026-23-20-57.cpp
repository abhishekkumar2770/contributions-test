class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int q = queries.size();

        vector<int> ans(q, -1);
        vector<vector<pair<int,int>>> pending(n);

        for (int i = 0; i < q; i++) {
            int a = queries[i][0];
            int b = queries[i][1];

            if (a > b) swap(a, b);

            if (a == b) {
                ans[i] = a;
            }
            else if (heights[a] < heights[b]) {
                ans[i] = b;
            }
            else {
                pending[b].push_back({max(heights[a], heights[b]), i});
            }
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        for (int i = 0; i < n; i++) {

            while (!pq.empty() && pq.top().first < heights[i]) {
                ans[pq.top().second] = i;
                pq.pop();
            }

            for (auto &p : pending[i]) {
                pq.push(p);
            }
        }

        return ans;
    }
};