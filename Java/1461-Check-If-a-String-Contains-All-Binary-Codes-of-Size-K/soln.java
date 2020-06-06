class Solution {
    public boolean hasAllCodes(String s, int k) {
        boolean [] seen = new boolean [1 << k];
        int n = s.length();
        int cur = 0;
        int unit = 1 << k;
        for(int i = 0; i < n; ++i) {
            cur = cur * 2 + s.charAt(i) - '0';
            if(i >= k && s.charAt(i - k) == '1') cur -= unit;
            if(i >= k - 1) seen[cur] = true;
        }
        for(int i = 0; i < (1 << k); ++i) {
            if(!seen[i]) return false;
        }
        return true;
    }
}
