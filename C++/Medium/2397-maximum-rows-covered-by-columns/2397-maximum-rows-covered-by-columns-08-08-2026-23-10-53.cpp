class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Convert every row into a bitmask
        vector<int> rowMask(m, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    rowMask[i] |= (1 << j);
                }
            }
        }

        int ans = 0;

        // Try every possible set of selected columns
        for (int mask = 0; mask < (1 << n); mask++) {

            // We must select exactly numSelect columns
            if (__builtin_popcount(mask) != numSelect)
                continue;

            int covered = 0;

            for (int i = 0; i < m; i++) {
                // All 1-columns of this row are selected
                if ((rowMask[i] & mask) == rowMask[i]) {
                    covered++;
                }
            }

            ans = max(ans, covered);
        }

        return ans;
    }
};