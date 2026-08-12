class Solution {
public:
    vector<string> ans;

    void solve(int idx, int n, int k, int cost, bool prevOne, string &s) {
        if (idx == n) {
            ans.push_back(s);
            return;
        }

        // Put 0
        s.push_back('0');
        solve(idx + 1, n, k, cost, false, s);
        s.pop_back();

        // Put 1
        if (!prevOne && cost + idx <= k) {
            s.push_back('1');
            solve(idx + 1, n, k, cost + idx, true, s);
            s.pop_back();
        }
    }

    vector<string> generateValidStrings(int n, int k) {
        ans.clear();
        string s;
        solve(0, n, k, 0, false, s);
        return ans;
    }
};