class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int time = computeTime(piles, mid);
            if (time <= H) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
        
    }
    
    int computeTime(vector<int> & piles, int speed) {
        int cnt = 0;
        int n = speed - 1;
        for(int pile : piles) {
            cnt += (pile + n) / speed;
        }
        return cnt;
    }
};
