class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int l = 0;
        int r = nums.size() - 1;
        long long ans = 0;

        while (l < r) {
            ans += nums[r - 1];  // second largest -> median
            l++;                 // use smallest as filler
            r -= 2;              // use largest and second largest
        }

        return ans;
    }
};