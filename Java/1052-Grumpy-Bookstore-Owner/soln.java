class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int n = grumpy.length, mx = 0, cur = 0, total = 0, un = 0;
        for(int i = 0; i < n; ++i) {
            total += customers[i];
            customers[i] *= grumpy[i];
        }
        for(int i = 0; i < n; ++i) {
            un += customers[i];
            cur += customers[i];
            if (i >= X) cur -= customers[i - X];
            mx = Math.max(mx, cur);
        }
        return total - (un - mx);
    }
}
