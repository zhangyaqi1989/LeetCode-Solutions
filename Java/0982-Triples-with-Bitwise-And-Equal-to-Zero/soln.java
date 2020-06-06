class Solution {
    public int countTriplets(int[] A) {
        int [] dp = new int[1 << 16];
        Arrays.fill(dp, -1);
        int ans = 0;
        for(int a : A) 
            for(int b : A) {
                int c = a & b;
                if (dp[c] == -1) {
                    dp[c] = 0;
                    for(int d : A) {
                        if ((d & c) == 0) ++dp[c];
                    }
                }
                ans += dp[c];
            }
        return ans;
    }
}
