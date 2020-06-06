class Solution {
    public String shortestCommonSupersequence(String A, String B) {
        int m = A.length(), n = B.length();
        String [][] dp = new String[m + 1][n + 1];
        for(String [] row : dp) Arrays.fill(row, "");
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if (A.charAt(i - 1) == B.charAt(j - 1)) dp[i][j] = dp[i - 1][j - 1] + A.charAt(i - 1);
                else dp[i][j] = dp[i - 1][j].length() > dp[i][j - 1].length() ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
        // System.out.println(dp[m][n]);
        StringBuilder sb = new StringBuilder();
        int i = 0, j = 0;
        for(char ch : dp[m][n].toCharArray()) {
            while (i < m && A.charAt(i) != ch) sb.append(A.charAt(i++));
            while (j < n && B.charAt(j) != ch) sb.append(B.charAt(j++));
            sb.append(ch);
            ++i;
            ++j;
        }
        
        return sb.toString() + A.substring(i) + B.substring(j);
    }
}
