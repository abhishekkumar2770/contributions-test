class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long sum(long long l, long long r) {
        return (l + r) * (r - l + 1) / 2;
    }

    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.begin(), inventory.end(), greater<int>());
        inventory.push_back(0);

        long long ans = 0;
        int n = inventory.size();

        for (int i = 0; i < n - 1 && orders > 0; i++) {
            long long curr = inventory[i];
            long long next = inventory[i + 1];
            long long cnt = i + 1;
            long long total = (curr - next) * cnt;

            if (orders >= total) {
                ans = (ans + cnt * (sum(next + 1, curr) % MOD)) % MOD;
                orders -= total;
            } else {
                long long full = orders / cnt;
                long long rem = orders % cnt;

                long long low = curr - full;

                ans = (ans + cnt * (sum(low + 1, curr) % MOD)) % MOD;
                ans = (ans + rem * low) % MOD;

                orders = 0;
            }
        }

        return ans % MOD;
    }
};