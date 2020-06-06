ass Solution {
    public int shipWithinDays(int[] weights, int D) {
        int lo = weights[0], hi = 0;
        for(int weight : weights) {
            if (weight > lo) lo = weight;
            hi += weight;
        }
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int days = computeDays(weights, mid);
            if (days > D) lo = mid + 1;
            else hi = mid;
        }
        return lo;
        
    }
    
    public int computeDays(int[] weights, int C) {
        int cur = 0, cnt = 1;
        for(int weight : weights) {
            if (cur + weight > C) {
                cur = weight;
                ++cnt;
            } else {
                cur += weight;
            }
        }
        return cnt;
    }
}
