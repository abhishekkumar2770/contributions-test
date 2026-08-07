class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<long long, long long> lastDay;
        long long day = 0;

        for (int task : tasks) {
            day++;

            if (lastDay.count(task) && day - lastDay[task] <= space) {
                day = lastDay[task] + space + 1;
            }

            lastDay[task] = day;
        }

        return day;
    }
};