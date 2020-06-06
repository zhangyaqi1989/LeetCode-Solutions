class Solution {
    public int divide(int dividend, int divisor) {
        long a = (long) dividend, b = (long) divisor;
        int sign = a * b < 0 ? -1 : 1;
        a = Math.abs(a);
        b = Math.abs(b);
        long ans = 0;
        while (a >= b) {
            long d = b;
            long q = 1;
            while (a >= d) {
                a -= d;
                ans += q;
                q <<= 1;
                d <<= 1;
            }
        }
        ans *= sign;
        return (Integer.MIN_VALUE <= ans && ans <= Integer.MAX_VALUE) ? (int) ans : Integer.MAX_VALUE;
    }
}
