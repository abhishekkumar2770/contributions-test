class Solution {
public:
    int mappedValue(int num, vector<int>& mapping) {
        if (num == 0)
            return mapping[0];

        string s = to_string(num);
        string t = "";

        for (char c : s) {
            t += char(mapping[c - '0'] + '0');
        }

        return stoi(t);
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> v;

        for (int i = 0; i < nums.size(); i++) {
            v.push_back({mappedValue(nums[i], mapping), i});
        }

        stable_sort(v.begin(), v.end());

        vector<int> ans;

        for (auto &p : v) {
            ans.push_back(nums[p.second]);
        }

        return ans;
    }
};