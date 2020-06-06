class Solution {
    public int maxDistToClosest(int[] seats) {
        int lo = -1, ans = 1, n = seats.length;
        for(int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                if (lo == -1) {
                    ans = Math.max(ans, i);
                } else {
                    ans = Math.max(ans, (i - lo) / 2);
                }
                lo = i;
            }
        }
        return Math.max(ans, n - 1 - lo);
    }
}
