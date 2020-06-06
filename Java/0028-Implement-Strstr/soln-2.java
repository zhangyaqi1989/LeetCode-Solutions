class Solution {
    public int strStr(String T, String P) {
        int n = T.length(), m = P.length();
        if (m == 0) return 0;
        int [] fail = computeFailArray(P);
        int j = 0, k = 0;
        // for(int num : fail) System.out.println(num);
        while (j < n) {
            if (T.charAt(j) == P.charAt(k)) {
                if (k == m - 1) {
                    return j - m + 1;
                }
                ++j;
                ++k;
            } else if (k > 0) {
                k = fail[k - 1];
            } else {
                ++j;
            }
        }
        return -1;
    }
    
    private int [] computeFailArray(String P) {
        int m = P.length();
        int [] fail = new int [m];
        int j = 1;
        int k = 0;
        while (j < m) {
            if (P.charAt(j) == P.charAt(k)) {
                fail[j] = k + 1;
                ++j;
                ++k;
            } else if (k > 0) {
                k = fail[k - 1];
            } else {
                ++j;
            }
        }
        return fail;
    }
}
