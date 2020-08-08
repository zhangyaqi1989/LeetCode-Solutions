class Solution {
    public boolean canConvertString(String s, String t, int k) {
        if(s.length() != t.length()) return false;
        int [] ds = new int [26];
        for(int i = 0; i < s.length(); ++i) {
            int d = t.charAt(i) - s.charAt(i);
            if(d < 0) d += 26;
            if(d != 0) {
                ++ds[d];
            }
        }
        for(int i = 1; i < 26; ++i) {
            if(ds[i] != 0) {
                int mx = i + (ds[i] - 1) * 26;
                if(mx > k) return false;
            }
        }
        return true;
    }
}
