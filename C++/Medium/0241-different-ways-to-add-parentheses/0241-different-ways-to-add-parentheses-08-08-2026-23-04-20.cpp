class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string, vector<int>> memo;
        
        function<vector<int>(string)> solve = [&](string s) {
            if (memo.count(s))
                return memo[s];

            vector<int> res;

            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                    char op = s[i];

                    vector<int> left = solve(s.substr(0, i));
                    vector<int> right = solve(s.substr(i + 1));

                    for (int a : left) {
                        for (int b : right) {
                            if (op == '+')
                                res.push_back(a + b);
                            else if (op == '-')
                                res.push_back(a - b);
                            else
                                res.push_back(a * b);
                        }
                    }
                }
            }

            // If there was no operator, it's just a number
            if (res.empty())
                res.push_back(stoi(s));

            return memo[s] = res;
        };

        return solve(expression);
    }
};