class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo = 1, hi = m * n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = count(m, n, mid);
            if (cnt < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
    
    int count(int m, int n, int num) {
        int cnt = 0;
        for(int factor = 1; factor <= m; ++factor) {
            cnt += min(n, num / factor);
        }
        return cnt;
    }
};
