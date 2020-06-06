class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (valid(weights, mid, D)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
    
private:
    bool valid(const vector<int> & weights, int capacity, int D) {
        int cnt = 1;
        int cur = 0;
        for(int w : weights) {
            if (cur + w <= capacity) {
                cur += w;
            } else {
                ++cnt;
                cur = w;
            }
        }
        return cnt <= D;
    }
};
