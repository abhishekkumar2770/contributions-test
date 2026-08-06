class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    void dfs(vector<int>& candidates, int idx, int target) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        if (idx == candidates.size() || target < 0)
            return;

        // Take current candidate (can be reused)
        cur.push_back(candidates[idx]);
        dfs(candidates, idx, target - candidates[idx]);
        cur.pop_back();

        // Skip current candidate
        dfs(candidates, idx + 1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target);
        return ans;
    }
};