typedef long long ll;
class Solution {
public:
    int divide(int dividend, int divisor) {
        ll a = dividend, b = divisor;
        int sign = a * b < 0 ? -1 : 1;
        a = abs(a), b = abs(b);
        ll ans = 0;
        while (a >= b) {
            ll d = b;
            ll q = 1;
            while (a >= d) {
                a -= d;
                ans += q;
                d <<= 1;
                q <<= 1;
            }
        }
        ans *= sign;
        return (INT_MIN <= ans && ans <= INT_MAX) ? ans : INT_MAX;
    }
};
