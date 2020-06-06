class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        // the smallest speed to success
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        const int n = piles.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int h = 0;
            for(const int & num : piles) {
                h += (num + mid - 1) / mid;
            }
            if (h > H) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
