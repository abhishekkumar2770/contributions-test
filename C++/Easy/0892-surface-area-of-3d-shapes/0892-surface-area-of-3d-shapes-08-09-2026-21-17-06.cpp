class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int area = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int h = grid[i][j];

                if (h == 0)
                    continue;

                // Top + bottom
                area += 2;

                // Front
                if (i == 0)
                    area += h;
                else
                    area += max(0, h - grid[i - 1][j]);

                // Back
                if (i == n - 1)
                    area += h;
                else
                    area += max(0, h - grid[i + 1][j]);

                // Left
                if (j == 0)
                    area += h;
                else
                    area += max(0, h - grid[i][j - 1]);

                // Right
                if (j == n - 1)
                    area += h;
                else
                    area += max(0, h - grid[i][j + 1]);
            }
        }

        return area;
    }
};