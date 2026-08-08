class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        // best[i][j] = maximum health we can have at (i,j)
        vector<vector<int>> best(m, vector<int>(n, -1));

        queue<pair<int, int>> q;

        health -= grid[0][0];

        if (health <= 0)
            return false;

        best[0][0] = health;
        q.push({0, 0});

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == m - 1 && y == n - 1)
                return true;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                int newHealth = best[x][y] - grid[nx][ny];

                if (newHealth <= 0)
                    continue;

                // Only visit if we reach this cell with better health.
                if (newHealth > best[nx][ny]) {
                    best[nx][ny] = newHealth;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }
};