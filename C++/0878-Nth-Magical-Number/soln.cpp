class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        long lcm = A * B / __gcd(A, B);
        long lo = min(A, B), hi = 1e14;
        while (lo < hi) {
            long mid = lo + (hi - lo) / 2;
            long cnt = mid / A + mid / B - mid / lcm;
            if (cnt < N) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo % (1000000007L);
    }
};
