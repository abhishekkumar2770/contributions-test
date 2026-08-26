class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end(), greater<int>());

        vector<long long> w;
        for (int i = 0; i < k; i++) {
            long long cur = 1LL * mul - i;
            w.push_back(max(1LL, cur));
        }

        long long ans = 0;

        for (int i = 0; i < k; i++) {
            ans += 1LL * nums[i] * w[i];
        }

        return ans;
    }
};