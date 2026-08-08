class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long mx1 = 0, mx2 = 0;

        // We need the two elements with the largest absolute values.
        for (int x : nums) {
            long long val = abs((long long)x);

            if (val >= mx1) {
                mx2 = mx1;
                mx1 = val;
            }
            else if (val > mx2) {
                mx2 = val;
            }
        }

        // Replace one element with +/- 10^5.
        return mx1 * mx2 * 100000LL;
    }
};