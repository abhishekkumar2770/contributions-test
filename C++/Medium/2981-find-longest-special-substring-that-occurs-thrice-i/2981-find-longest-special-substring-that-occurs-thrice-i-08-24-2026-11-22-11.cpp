class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int ans = -1;

        for (int len = 1; len <= n; len++) {
            unordered_map<string, int> cnt;

            for (int i = 0; i + len <= n; i++) {
                string sub = s.substr(i, len);

                bool special = true;
                for (char c : sub) {
                    if (c != sub[0]) {
                        special = false;
                        break;
                    }
                }

                if (special)
                    cnt[sub]++;
            }

            for (auto &p : cnt) {
                if (p.second >= 3)
                    ans = max(ans, len);
            }
        }

        return ans;
    }
};