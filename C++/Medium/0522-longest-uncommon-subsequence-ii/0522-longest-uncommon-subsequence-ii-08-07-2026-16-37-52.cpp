class Solution {
public:
    bool isSubsequence(string &a, string &b) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) i++;
            j++;
        }
        return i == a.size();
    }

    int findLUSlength(vector<string>& strs) {
        int ans = -1;

        for (int i = 0; i < strs.size(); i++) {
            bool ok = true;
            for (int j = 0; j < strs.size(); j++) {
                if (i == j) continue;
                if (isSubsequence(strs[i], strs[j])) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                ans = max(ans, (int)strs[i].size());
        }

        return ans;
    }
};