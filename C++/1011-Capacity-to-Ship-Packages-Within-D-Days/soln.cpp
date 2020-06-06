class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        // this is a typical binary search problem
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int days = computeDays(weights, mid);
            if (days > D) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
    
    int computeDays(vector<int> & weights, int C) {
        int cur = 0, cnt = 0;
        for(int weight : weights) {
            if (cur + weight > C) {
                ++cnt;
                cur = weight;
            } else {
                cur += weight;
            }
        }
        return cnt + 1;
    }
};
