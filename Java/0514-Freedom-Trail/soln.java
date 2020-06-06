class Solution {
    public int findRotateSteps(String ring, String key) {
        ArrayList<Integer> [] idxes = new ArrayList[26];
        for(int i = 0; i < 26; ++i) idxes[i] = new ArrayList<>();
        int n = ring.length();
        for(int i = 0; i < n; ++i) {
            idxes[ring.charAt(i) - 'a'].add(i);
        }
        int [] dp = new int[n];
        for(int i : idxes[key.charAt(0) - 'a']) {
            dp[i] = Math.min(i, n - i) + 1;
        }
        int m = key.length();
        char pre = key.charAt(0);
        for(int i = 1; i < m; ++i) {
            char ch = key.charAt(i);
            for(int j : idxes[ch - 'a']) {
                int temp = Integer.MAX_VALUE;
                for(int k : idxes[pre - 'a']) {
                    if (k >= j) temp = Math.min(temp, dp[k] + Math.min(k - j, j - k + n) + 1);
                    else temp = Math.min(temp, dp[k] + Math.min(j - k, k - j + n) + 1);
                }
                dp[j] = temp;
            }
            pre = ch;
        }
        int ans = Integer.MAX_VALUE;
        for(int j : idxes[pre - 'a']) {
            ans = Math.min(ans, dp[j]);
        }
        return ans;
    }
}
