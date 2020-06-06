typedef long long ll;
class Solution {
public:
    int arrangeCoins(int n) {
        ll lo = 0, hi = n;
        while (lo < hi) {
            ll mid = hi - (hi - lo) / 2;
            ll num = (1 + mid) * mid / 2;
            if (n >= num) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};
