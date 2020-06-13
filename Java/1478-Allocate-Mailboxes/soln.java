class Solution {
    public int [][] memo;
    public int minDistance(int[] houses, int k) {
        int n = houses.length;
        Arrays.sort(houses);
        memo = new int[n + 1][n + 1];
        for(int i = 0; i < n + 1; ++i) Arrays.fill(memo[i], -1);
        return helper(houses, 0, k);
    }
    
    private int helper(int [] houses, int idx, int k) {
        int n = houses.length;
        if (n - idx <= k) return 0;
        if (k < 0) return -1;
        if(memo[idx][k] != -1) return memo[idx][k];
        int ans = -1;
        int lo = idx;
        for(int nxt = idx + 1; nxt <= n; ++nxt) {
            int hi = nxt - 1;
            int place = houses[lo + (hi - lo) / 2];
            int cost = 0;
            for(int i = lo; i <= hi; ++i) cost += Math.abs(place - houses[i]);
            int tail = helper(houses, nxt, k - 1);
            if(tail != -1) {
                if(ans == -1) ans = tail + cost;
                else ans = Math.min(ans, tail + cost);
            }
        }
        return memo[idx][k] = ans;
    }
}
