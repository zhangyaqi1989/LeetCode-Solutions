class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        char [] c1 = s1.toCharArray(), c2 = s2.toCharArray(), c3 = s3.toCharArray();
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if ((n1 + n2) != n3) return false;
        boolean [][] dp = new boolean [n1 + 1][n2 + 1];
        for(int i = 0; i < n1 + 1; ++i) {
            for(int j = 0; j < n2 + 1; ++j) {
                if (i == 0 && j == 0) dp[i][j] = true;
                else if (i == 0) {
                    if (c2[j - 1] == c3[j - 1] && dp[i][j - 1]) dp[i][j] = true;
                } else if (j == 0) {
                    if (c1[i - 1] == c3[i - 1] && dp[i - 1][j]) dp[i][j] = true;
                } else {
                    if ((c1[i - 1] == c3[i + j - 1] && dp[i - 1][j]) || (c2[j - 1] == c3[i + j - 1] && dp[i][j - 1]))
                        dp[i][j] = true;
                }
            }
        }
        return dp[n1][n2];
    }
}
