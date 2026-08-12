class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;

        for (char c : s)
            freq[c]++;

        priority_queue<pair<int, char>> pq;

        for (auto &it : freq)
            pq.push({it.second, it.first});

        string ans;
        pair<int, char> prev = {0, '#'};

        while (!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();

            ans += ch;
            count--;

            // Put previous character back
            if (prev.first > 0)
                pq.push(prev);

            prev = {count, ch};
        }

        if (ans.size() != s.size())
            return "";

        return ans;
    }
};