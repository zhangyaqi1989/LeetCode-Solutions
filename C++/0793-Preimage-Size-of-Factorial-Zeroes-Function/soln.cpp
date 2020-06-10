class Solution {
public:
    int preimageSizeFZF(int K) {
        long long lo = 0, hi = 1LL << 63 - 1;
        while (lo < hi) {
            // cout << lo << " " << hi << endl;
            long long mid = lo + (hi - lo) / 2;
            if (count(mid) < K) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return count(lo) == K ? 5 - lo % 5 : 0;
    }
    
    long long count(long long num) {
        long long cnt = 0;
        while (num != 0) {
            cnt += num / 5LL;
            num /= 5LL;
        }
        return cnt;
    }
};
