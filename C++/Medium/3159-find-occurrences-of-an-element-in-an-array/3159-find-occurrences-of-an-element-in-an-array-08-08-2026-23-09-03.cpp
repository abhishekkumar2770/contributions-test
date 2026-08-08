class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> pos;
        
        // Store all indices where x occurs
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                pos.push_back(i);
            }
        }

        vector<int> ans;

        // queries[i] is 1-indexed
        for (int q : queries) {
            if (q <= pos.size()) {
                ans.push_back(pos[q - 1]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};