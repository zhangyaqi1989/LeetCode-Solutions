class Solution {
    public int minCut(String s) {
        int n = s.length();
        int [] cuts = new int [n + 1];
        for(int i = 0; i < n + 1; ++i) {
            cuts[i] = i - 1;
        }
        for(int i = 0; i < n; ++i) {
            int l = i, r = i;
            while (l >= 0 && r < n && s.charAt(l) == s.charAt(r)) {
                cuts[r + 1] = Math.min(cuts[r + 1], cuts[l] + 1);
                --l;
                ++r;
            }
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s.charAt(l) == s.charAt(r)) {
                cuts[r + 1] = Math.min(cuts[r + 1], cuts[l] + 1);
                --l;
                ++r;
            }
        }
        return cuts[n];
    }
}
