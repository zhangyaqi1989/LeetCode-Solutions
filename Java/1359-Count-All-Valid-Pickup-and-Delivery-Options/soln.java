class Solution {
    public int countOrders(int n) {
        final int MOD = 1000000007;
        int f = 1;
        for(int i = 2; i <= n; ++i) {
            int new_f =(int) ((long) i * ((long) f * (2 * i - 1)) % MOD);
            f = new_f;
        }
        return f;
}
