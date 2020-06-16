class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        int n = bloomDay.length;
        if(n < m * k) return -1;
        int lo = bloomDay[0], hi = bloomDay[0];
        for(int i = 1; i < n; ++i) {
            lo = Math.min(lo, bloomDay[i]);
            hi = Math.max(hi, bloomDay[i]);
        }
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(valid(bloomDay, m, k, mid)) hi = mid;
            else lo = mid + 1;
        }
        return valid(bloomDay, m, k, lo) ? lo : -1;
        
    }
    
    public boolean valid(int [] bloomDay, int m, int k, int day) {
        int lo = 0, n = bloomDay.length;
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if((day >= bloomDay[i]) != (day >= bloomDay[lo])) {
                if(day >= bloomDay[lo]) {
                    cnt += (i - lo) / k;
                }
                lo = i;
            }
        }
        if(day >= bloomDay[lo]) cnt += (n - lo) / k;
        return cnt >= m;
    }
}
