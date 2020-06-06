class Solution {
public:
    int nthUglyNumber(int n, int A, int B, int C) {
        long a = (long) A, b = (long) B, c = (long) C;
        long ab = (a * b) / __gcd(a, b);
        long bc = (b * c) / __gcd(b, c);
        long ac = (a * c) / __gcd(a, c);
        long abc = (ab * c) / __gcd(ab, c);
        long lo = 1, hi = 2000000000;
        while (lo < hi) {
            long mid = lo + (hi - lo) / 2;
            long count = mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac + mid / abc;
            if (count < n) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
