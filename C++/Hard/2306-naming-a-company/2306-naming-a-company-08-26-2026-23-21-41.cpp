class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> groups(26);

        for (string &s : ideas) {
            groups[s[0] - 'a'].insert(s.substr(1));
        }

        long long ans = 0;

        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {

                int common = 0;

                for (auto &suffix : groups[i]) {
                    if (groups[j].count(suffix))
                        common++;
                }

                long long uniqueI = groups[i].size() - common;
                long long uniqueJ = groups[j].size() - common;

                ans += 2LL * uniqueI * uniqueJ;
            }
        }

        return ans;
    }
};