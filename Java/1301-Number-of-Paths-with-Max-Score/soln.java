class Solution {
    public int[] pathsWithMaxScore(List<String> board) {
        long mod = 1000000007;
        int n = board.size();
        int[][][] dp = new int[n + 1][n + 1][2];
        for(int i = 0; i < n + 1; ++i) {
            for(int j = 0; j < n + 1; ++j) {
                dp[i][j][0] = -1;
                dp[i][j][1] = 0;
            }
        }
        int [] dis = {0, 1, 1};
        int [] djs = {1, 0, 1};
        dp[n - 1][n - 1][0] = 0;
        dp[n - 1][n - 1][1] = 1;
        for(int i = n - 1; i >= 0; --i) {
            for(int j = n - 1; j >= 0; --j) {
                if (board.get(i).charAt(j) == 'X' || board.get(i).charAt(j) == 'S') continue;
                for(int k = 0; k < 3; ++k) {
                    int ni = i + dis[k], nj = j + djs[k];
                    if (dp[ni][nj][0] > dp[i][j][0]) {
                        dp[i][j][0] = dp[ni][nj][0];
                        dp[i][j][1] = dp[ni][nj][1];
                    } else if (dp[ni][nj][0] == dp[i][j][0]) {
                        dp[i][j][1] = (int) (((long) dp[ni][nj][1] + dp[i][j][1]) % mod);
                    }
                }
                if (dp[i][j][0] != -1) {
                    dp[i][j][0] += (board.get(i).charAt(j) == 'E' ? 0 : (board.get(i).charAt(j) - '0'));
                }
            }
        }
        return new int[] {Math.max(dp[0][0][0], 0), dp[0][0][1]};
    }
}
