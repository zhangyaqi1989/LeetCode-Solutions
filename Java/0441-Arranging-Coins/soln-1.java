class Solution {
    public int arrangeCoins(int n) {
        // (1 + m) * m / 2
        long lo = 0, hi = n;
        while (lo < hi) {
            long mid = hi - (hi - lo) / 2;
            long num = (1 + mid) * mid / 2;
            if (num <= n) lo = mid; // n >= num
            else hi = mid - 1; // num > n
        }
        return (int) lo;
    }
}
