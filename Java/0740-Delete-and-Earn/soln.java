class Solution {
    public int deleteAndEarn(int[] nums) {
        // rob
        final int N = 10001;
        int [] counter = new int [N];
        for(int num : nums) ++ counter[num];
        int [] dp = new int [N];
        for(int i = 1; i < N; ++i) {
            if(counter[i] == 0) dp[i] = dp[i - 1];
            else {
                int val = i * counter[i];
                dp[i] = val + (i == 1 ? 0 : dp[i - 2]);
                if (dp[i - 1] > dp[i]) dp[i] = dp[i - 1];
            }
        }
        return dp[N - 1];
    }
}
