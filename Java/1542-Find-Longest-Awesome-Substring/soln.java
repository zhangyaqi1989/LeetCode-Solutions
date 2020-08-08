class Solution {
    public int longestAwesome(String s) {
        int n = s.length();
        final int INF = 1000000;
        int [] seen = new int [1 << 10];
        Arrays.fill(seen, INF);
        seen[0] = -1;
        int mask = 0;
        int ans = 1;
        for(int i = 0; i < n; ++i) {
            mask ^= (1 << (s.charAt(i) - '0'));
            ans = Math.max(ans, i - seen[mask]);
            for(int j = 0; j < 10; ++j) {
                int temp_mask = mask ^ (1 << j);
                ans = Math.max(ans, i - seen[temp_mask]);
            }
            if(seen[mask] == INF) seen[mask] = i; 
        }
        return ans;
    }
}
