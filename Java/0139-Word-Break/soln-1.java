class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> words = new HashSet<>();
        for(String word : wordDict) words.add(word);
        int n = s.length();
        boolean [] dp = new boolean[n + 1];
        dp[0] = true;
        for(int i = 1; i <= n; ++i) {
            boolean val = false;
            for(int j = i - 1; j >= 0; --j) {
                if (words.contains(s.substring(j, i)) && dp[j]) {
                    val = true;
                    break;
                }
            }
            dp[i] = val;
        }
        return dp[n];
    }
}
