class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size() > 1440) return 0;
        vector<int> times;
        for(string time : timePoints) {
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3));
            times.push_back(60 * h + m);
        }
        sort(times.begin(), times.end());
        int n = times.size();
        int ans = times.front() + 1440 - times.back();
        for(int i = 0; i < n - 1; ++i) {
            ans = min(ans, times[i + 1] - times[i]);
        }
        return ans;
    }
};
