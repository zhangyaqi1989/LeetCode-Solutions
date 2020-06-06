class Solution {
    public int minStickers(String[] stickers, String target) {
        int n = target.length();
        int N = (1 << n);
        int [] dp = new int [N];
        final int INF = n + 1;
        Arrays.fill(dp, INF);
        dp[0] = 0;
        for(int i = 0; i < N; ++i) {
            if (dp[i] == INF) continue;
            for(String s : stickers) {
                int now = i;
                for(char ch : s.toCharArray()) {
                    for(int j = 0; j < n; ++j) {
                        if (target.charAt(j) == ch && (now & (1 << j)) == 0) {
                            now |= (1 << j);
                            break;
                        }
                    }
                }
                dp[now] = Math.min(dp[now], dp[i] + 1);
            }
        }
        return dp[N - 1] == INF ? -1 : dp[N - 1];
    }
}
