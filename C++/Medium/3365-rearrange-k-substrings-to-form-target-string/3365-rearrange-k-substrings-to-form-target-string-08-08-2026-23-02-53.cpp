class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        int len = n / k;

        unordered_map<string, int> mp;

        // Store all substrings of s
        for (int i = 0; i < n; i += len) {
            mp[s.substr(i, len)]++;
        }

        // Match them with substrings of t
        for (int i = 0; i < n; i += len) {
            string sub = t.substr(i, len);

            if (mp[sub] == 0)
                return false;

            mp[sub]--;
        }

        return true;
    }
};