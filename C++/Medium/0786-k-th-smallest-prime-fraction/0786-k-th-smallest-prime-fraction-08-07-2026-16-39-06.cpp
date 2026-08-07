class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();

        auto cmp = [&](const pair<int,int>& a, const pair<int,int>& b) {
            return (long long)arr[a.first] * arr[b.second] >
                   (long long)arr[b.first] * arr[a.second];
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

        // Initially push smallest fraction for each denominator
        for (int j = 1; j < n; j++)
            pq.push({0, j});

        while (--k) {
            auto [i, j] = pq.top();
            pq.pop();

            if (i + 1 < j)
                pq.push({i + 1, j});
        }

        auto [i, j] = pq.top();
        return {arr[i], arr[j]};
    }
};