class Solution {
public:
    string turnUp(string s, int i) {
        s[i] = (s[i] - '0' + 1) % 10 + '0';
        return s;
    }

    string turnDown(string s, int i) {
        s[i] = (s[i] - '0' + 9) % 10 + '0';
        return s;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());

        // Starting position itself is blocked
        if (dead.count("0000"))
            return -1;

        queue<string> q;
        unordered_set<string> visited;

        q.push("0000");
        visited.insert("0000");

        int moves = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                string current = q.front();
                q.pop();

                if (current == target)
                    return moves;

                // Try rotating each of the 4 wheels
                for (int i = 0; i < 4; i++) {
                    string next1 = turnUp(current, i);
                    string next2 = turnDown(current, i);

                    if (!dead.count(next1) && !visited.count(next1)) {
                        visited.insert(next1);
                        q.push(next1);
                    }

                    if (!dead.count(next2) && !visited.count(next2)) {
                        visited.insert(next2);
                        q.push(next2);
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};