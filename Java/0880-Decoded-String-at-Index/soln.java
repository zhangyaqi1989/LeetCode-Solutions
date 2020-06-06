class Solution {
    public String decodeAtIndex(String S, int K) {
        long N = 0;
        int i = 0, n = S.length();
        for(; i < n; ++i) {
            char ch = S.charAt(i);
            N = Character.isDigit(ch) ? N * (ch - '0'): N + 1;
            if (N >= K) break;
        }
        while(i >= 0) {
            char ch = S.charAt(i);
            if (Character.isDigit(ch)) {
                N /= (ch - '0');
                K %= N;
            } else {
                if (K % N == 0) return Character.toString(ch);
                --N;
            }
            --i;
        }
        return "";
    }
}
