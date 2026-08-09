class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int ans = 0;
        int len = 1;
        int vowels = 1;

        for (int i = 1; i < word.size(); i++) {

            if (word[i] == word[i - 1]) {
                // Same vowel, continue
                len++;
            }
            else if (word[i] > word[i - 1]) {
                // Move to the next vowel
                len++;
                vowels++;
            }
            else {
                // Order broke, start again
                len = 1;
                vowels = 1;
            }

            // All 5 vowels are present
            if (vowels == 5) {
                ans = max(ans, len);
            }
        }

        return ans;
    }
};