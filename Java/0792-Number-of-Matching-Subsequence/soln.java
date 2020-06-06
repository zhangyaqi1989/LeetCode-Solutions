class Solution {
    public int numMatchingSubseq(String S, String[] words) {
        int cnt = 0;
        for(String word : words) {
            if (isSubseq(S, word)) ++cnt;
        }
        return cnt;
    }

    public boolean isSubseq(String S, String t) {
        // check if t is a subsequence of S
        int ns = S.length(), nt = t.length();
        if (nt > ns) return false;
        int j = 0;
        for(int i = 0; i < ns; ++i) {
            if (S.charAt(i) == t.charAt(j)) {
                ++j;
                if (j == nt) return true;
            }
        }
        return false;
    }
}
