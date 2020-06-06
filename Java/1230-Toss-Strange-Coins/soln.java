class Solution {
    public double probabilityOfHeads(double[] prob, int target) {
        int n = prob.length;
        double [] dp = new double [target + 1];
        dp[0] = 1;
        for(int i = 0; i < n; ++i) {
            double [] temp = new double [target + 1];
            double head = prob[i];
            double tail = 1 - head;
            temp[0] = dp[0] * tail;
            for(int j = 1; j <= Math.min(target, i + 1); ++j) {
                temp[j] = dp[j] * tail + dp[j - 1] * head;
            }
            dp = temp;
        }
        return dp[target];
    }
}
