class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Directions: North, East, South, West
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        unordered_set<long long> blocked;

        // Encode (x, y) into one long long
        for (auto &ob : obstacles) {
            long long key = ((long long)ob[0] << 32) ^ (unsigned int)ob[1];
            blocked.insert(key);
        }

        int x = 0, y = 0;
        int dir = 0;
        int ans = 0;

        for (int cmd : commands) {
            if (cmd == -2) {
                dir = (dir + 3) % 4;  // Turn left
            }
            else if (cmd == -1) {
                dir = (dir + 1) % 4;  // Turn right
            }
            else {
                for (int step = 0; step < cmd; step++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    long long key =
                        ((long long)nx << 32) ^ (unsigned int)ny;

                    if (blocked.count(key))
                        break;

                    x = nx;
                    y = ny;

                    ans = max(ans, x * x + y * y);
                }
            }
        }

        return ans;
    }
};