typedef long long ll;
class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        // binary search
        ll lo = 1, hi = LLONG_MAX;
        int AB = (A * B) / __gcd(A, B); // LCM
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            ll cnt = mid / A + mid / B - mid / (AB);
            if (cnt < N) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo % 1000000007;
    }
};
