class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;

        vector<long long> fact(n + 1), invFact(n + 1);
        fact[0] = 1;

        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[n] = modPow(fact[n], MOD - 2);

        for (int i = n; i > 0; i--)
            invFact[i - 1] = invFact[i] * i % MOD;

        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    int countVisiblePeople(int n, int pos, int k) {
        int left = pos;
        int right = n - pos - 1;
        int total = left + right;

        if (k > total) return 0;

        long long ways = nCr(total, k);
        ways = ways * 2 % MOD;   // direction of person at pos

        return (int)ways;
    }
};