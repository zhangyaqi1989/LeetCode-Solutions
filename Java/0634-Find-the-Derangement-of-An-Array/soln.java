class Solution {
    public int findDerangement(int n) {
        // f(n) = (n - 1) * (f(n - 1) + f(n - 2))
        if (n <= 2) return n - 1;
        long mod = 1000000007;
        long a = 0, b = 1;
        for(int i = 3; i <= n; ++i) {
            long temp = (i - 1) * (a + b) % mod;
            a = b;
            b = temp;
        }
        return (int) b;
    }
}
