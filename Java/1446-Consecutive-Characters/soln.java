class Solution {
    public int maxPower(String s) {
        int n = s.length(), mx = 1, lo = 0;
        for(int i = 0; i < n; ++i) {
            if(s.charAt(i) != s.charAt(lo)) {
                mx = Math.max(mx, i - lo);
                lo = i;
            }
        }
        return Math.max(mx, n - lo);
    }
}
