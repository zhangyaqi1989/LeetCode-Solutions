class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int [][] dp = new int[m + 1][n + 1];
        for(String str : strs) {
            int [] zos = count(str);
            int zs = zos[0], os = zos[1];
            for(int i = m; i >= zs; --i) {
                for(int j = n; j >= os; --j) {
                    dp[i][j] = Math.max(dp[i][j], dp[i - zs][j - os] + 1);
                }
            }
        }
        return dp[m][n];
    }
    
    public int[] count(String str) {
        int [] zos = new int [2];
        for(char ch : str.toCharArray()) {
            if (ch == '0') ++zos[0];
            else ++zos[1];
        }
        return zos;
    }
}
