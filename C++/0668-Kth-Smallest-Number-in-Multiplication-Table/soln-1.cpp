class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        // k is always available
        if (n > m) swap(n, m);
        int lo = 1, hi = m * n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = 0;
            for(int i = 1; i <= n; ++i) {
                int num = min(m, mid / i);
                cnt += num;
            }
            if (cnt < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
