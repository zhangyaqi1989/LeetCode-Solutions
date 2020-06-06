class Solution {
    public int maxDotProduct(int[] nums1, int[] nums2) {
        int n1 = nums1.length, n2 = nums2.length;
        int [][] dp = new int [n1 + 1][n2 + 1];
        for(int i = 0; i < n1 + 1; ++i) Arrays.fill(dp[i], Integer.MIN_VALUE);
        for(int i = n1 - 1; i >= 0; --i) {
            for(int j = n2 - 1; j >= 0; --j) {
                dp[i][j] = Math.max(Math.max(dp[i + 1][j], dp[i][j + 1]), nums1[i] * nums2[j] + Math.max(0, dp[i + 1][j + 1]));
            }
        }
        return dp[0][0];
    }
}
