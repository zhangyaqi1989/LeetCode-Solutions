class Solution {
    public boolean isSubsequence(String s, String t) {
        // check whether s is a subsequence of t
        int sn = s.length(), tn = t.length();
        if (sn > tn) return false;
        if (sn == 0) return true;
        int j = 0;
        for(int i = 0; i < tn; ++i) {
            if (t.charAt(i) == s.charAt(j)) {
                ++j;
                if(j == sn) return true;
            }
        }
        return false;
    }
}
