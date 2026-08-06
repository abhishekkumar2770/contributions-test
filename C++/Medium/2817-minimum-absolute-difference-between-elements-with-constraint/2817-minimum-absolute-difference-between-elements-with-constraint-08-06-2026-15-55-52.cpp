class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        if (x == 0) return 0;

        multiset<int> st;
        int ans = INT_MAX;
        int n = nums.size();

        for (int i = x; i < n; i++) {
            st.insert(nums[i - x]);

            auto it = st.lower_bound(nums[i]);

            if (it != st.end())
                ans = min(ans, abs(*it - nums[i]));

            if (it != st.begin()) {
                --it;
                ans = min(ans, abs(*it - nums[i]));
            }
        }

        return ans;
    }
};