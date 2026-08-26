class Solution {
public:
    void dfs(string cur,
             unordered_map<string, vector<pair<string,double>>> &g,
             unordered_map<string,double> &val) {

        for (auto &it : g[cur]) {
            string nxt = it.first;
            double rate = it.second;

            if (!val.count(nxt)) {
                val[nxt] = val[cur] * rate;
                dfs(nxt, g, val);
            }
        }
    }

    double maxAmount(string initialCurrency,
                     vector<vector<string>>& pairs1,
                     vector<double>& rates1,
                     vector<vector<string>>& pairs2,
                     vector<double>& rates2) {

        unordered_map<string, vector<pair<string,double>>> g1, g2;

        for (int i = 0; i < pairs1.size(); i++) {
            string a = pairs1[i][0];
            string b = pairs1[i][1];
            double r = rates1[i];

            g1[a].push_back({b, r});
            g1[b].push_back({a, 1.0 / r});
        }

        for (int i = 0; i < pairs2.size(); i++) {
            string a = pairs2[i][0];
            string b = pairs2[i][1];
            double r = rates2[i];

            g2[a].push_back({b, r});
            g2[b].push_back({a, 1.0 / r});
        }

        unordered_map<string,double> day1;
        day1[initialCurrency] = 1.0;
        dfs(initialCurrency, g1, day1);

        double ans = 1.0;

        for (auto &[currency, amount] : day1) {

            unordered_map<string,double> day2;
            day2[currency] = 1.0;
            dfs(currency, g2, day2);

            if (day2.count(initialCurrency)) {
                ans = max(ans, amount * day2[initialCurrency]);
            }
        }

        return ans;
    }
};