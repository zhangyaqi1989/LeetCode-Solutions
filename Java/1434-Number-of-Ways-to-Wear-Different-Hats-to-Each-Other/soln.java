class Solution {
    public int numberWays(List<List<Integer>> hats) {
        int n = hats.size();
        List<Integer> [] people = new List[41];
        for(int i = 0; i < 41; ++i) people[i] = new ArrayList<>();
        for(int i = 0; i < n; ++i) {
            for(int h : hats.get(i)) {
                people[h].add(i);
            }
        }
        int [] dp = new int [1 << n];
        dp[0] = 1;
        final int MOD = 1000000007;
        for(int hat = 1; hat <= 40; ++hat) {
            int [] new_dp = dp.clone();
            for(int state = 0; state < (1 << n); ++state) {
                for(int p : people[hat]) {
                    if((state & (1 << p)) == 0) {
                        int new_state = (state | (1 << p));
                        new_dp[new_state] += dp[state];
                        if(new_dp[new_state] >= MOD) new_dp[new_state] -= MOD;
                    }
                }
            }
            dp = new_dp;
        }
        return dp[(1 << n) - 1];
    }
}
