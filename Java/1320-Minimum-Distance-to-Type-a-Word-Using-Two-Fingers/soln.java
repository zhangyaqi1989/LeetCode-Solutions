class Solution {
    public int minimumDistance(String word) {
        int [][] memo = new int [300][26 * 26];
        for(int i = 0; i < 300; ++i) Arrays.fill(memo[i], -1);
        int ans = Integer.MAX_VALUE;
        for(char f1 = 'A'; f1 <= 'Z'; ++f1) {
            for(char f2 = 'A'; f2 <= 'Z'; ++f2) {
                ans = Math.min(ans, Dfs(word, 0, f1, f2, memo));
            }
        }
        return ans;
    }
    private int Distance(char c1, char c2) {
        int i1 = c1 - 'A', i2 = c2 - 'A';
        return Math.abs(i1 / 6 - i2 / 6) + Math.abs(i1 % 6 - i2 % 6);
    }
    private int Dfs(String word, int idx, char f1, char f2, int[][] memo) {
        if (idx == word.length()) return 0;
        int col = (f1 - 'A') * 26 + (f2 - 'A');
        if (memo[idx][col] != -1) return memo[idx][col];
        char c = word.charAt(idx);
        int ans = Math.min(Distance(c, f1) + Dfs(word, idx + 1, c, f2, memo), Distance(c, f2) + Dfs(word, idx + 1, f1, c, memo));
        memo[idx][col] = ans;
        return ans;
    }
}
