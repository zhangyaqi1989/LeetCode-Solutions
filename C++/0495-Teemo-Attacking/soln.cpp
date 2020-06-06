class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0, lo = 0, hi = 0;
        timeSeries.push_back(10000001);
        for(int time : timeSeries) {
            if (time > hi) {
                ans += hi - lo;
                lo = time;
                hi = time + duration;
            } else {
                hi = time + duration;
            }
        }
        return ans;
    }
};
