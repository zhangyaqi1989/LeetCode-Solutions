class Solution {
    public boolean backspaceCompare(String S, String T) {
        int ns = S.length(), nt = T.length();
        int i = ns - 1, j = nt - 1;
        int bs = 0, bt = 0;
        while (i >= 0 || j >= 0) {
            while (i >= 0 && (bs > 0 || S.charAt(i) == '#')) {
                if (S.charAt(i--) == '#') ++bs;
                else --bs;
            }
            // System.out.println(i);
            while (j >= 0 && (bt > 0 || T.charAt(j) == '#')) {
                if (T.charAt(j--) == '#') ++bt;
                else --bt;
            }
            if (i >= 0 && j >= 0) {
                if (S.charAt(i) != T.charAt(j)) return false;
                --i;
                --j;
            } else {
                break;
            }
        }
        return i == j;
    }
}
