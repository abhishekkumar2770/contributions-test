class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int target = n / 4;

        for (int i = 0; i < n; i++) {
            int j = upper_bound(arr.begin(), arr.end(), arr[i]) - arr.begin();
            if (j - i > target)
                return arr[i];
            i = j - 1;
        }

        return -1;
    }
};