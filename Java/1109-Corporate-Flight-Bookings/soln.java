class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int [] counter = new int [n + 2];
        for(int [] booking : bookings) {
            int i = booking[0], j = booking[1], k = booking[2];
            counter[i] += k;
            counter[j + 1] -= k;
        }
        int [] ans = new int[n];
        int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            cnt += counter[i];
            ans[i - 1] = cnt;
        }
        return ans;
    }
}
