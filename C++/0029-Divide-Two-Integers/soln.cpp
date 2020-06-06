class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        long long a = labs(dividend);
        long long b = labs(divisor);
        int res = 0;
        while (a >= b) {
            long unit = b;
            long q = 1;
            while (a >= unit) {
                res += q;
                a -= unit;
                unit <<= 1;
                q <<= 1;
            }
        }
        return sign * res;
    }
};
