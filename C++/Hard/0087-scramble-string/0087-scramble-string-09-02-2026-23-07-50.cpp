#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::unordered_map<std::string, std::unordered_map<std::string, bool>> memo;

    bool isScramble(std::string s1, std::string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        if (s1 == s2) {
            return true;
        }

        if (memo.count(s1) && memo[s1].count(s2)) {
            return memo[s1][s2];
        }

        std::unordered_map<char, int> count;
        for (char c : s1) count[c]++;
        for (char c : s2) count[c]--;

        for (auto const& [key, val] : count) {
            if (val != 0) {
                return memo[s1][s2] = false;
            }
        }

        int n = s1.length();
        for (int i = 1; i < n; ++i) {
            // Case 1: No swap
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i, n - i), s2.substr(i, n - i))) {
                return memo[s1][s2] = true;
            }

            // Case 2: Swap
            if (isScramble(s1.substr(0, i), s2.substr(n - i, i)) &&
                isScramble(s1.substr(i, n - i), s2.substr(0, n - i))) {
                return memo[s1][s2] = true;
            }
        }

        return memo[s1][s2] = false;
    }
};
