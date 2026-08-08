class Solution {
public:
    long long specialPalindrome(long long n) {
        string s = to_string(n);
        int len = s.size();

        for (int L = len; L <= 18; L++) {
            long long ans = LLONG_MAX;

            // Choose which digits are present.
            for (int mask = 1; mask < (1 << 9); mask++) {
                int total = 0;
                int oddCount = 0;
                int center = -1;

                for (int d = 1; d <= 9; d++) {
                    if (mask & (1 << (d - 1))) {
                        total += d;

                        if (d % 2 == 1) {
                            oddCount++;
                            center = d;
                        }
                    }
                }

                // Total number of digits must be L.
                // A palindrome can have at most one odd frequency.
                if (total != L || oddCount > 1)
                    continue;

                vector<int> half;

                for (int d = 1; d <= 9; d++) {
                    if (mask & (1 << (d - 1))) {
                        for (int j = 0; j < d / 2; j++) {
                            half.push_back(d);
                        }
                    }
                }

                sort(half.begin(), half.end());

                do {
                    string candidate;

                    // Left half
                    for (int x : half) {
                        candidate += char('0' + x);
                    }

                    // Middle digit
                    if (center != -1) {
                        candidate += char('0' + center);
                    }

                    // Right half
                    for (int i = (int)half.size() - 1; i >= 0; i--) {
                        candidate += char('0' + half[i]);
                    }

                    if ((int)candidate.size() != L)
                        continue;

                    if (L > len || candidate > s) {
                        long long value = stoll(candidate);
                        ans = min(ans, value);
                    }

                } while (next_permutation(half.begin(), half.end()));
            }

            if (ans != LLONG_MAX)
                return ans;
        }

        return -1;
    }
};