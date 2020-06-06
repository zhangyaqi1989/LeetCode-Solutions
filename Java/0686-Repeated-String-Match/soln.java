class Solution {
    public int repeatedStringMatch(String A, String B) {
        int na = A.length(), nb = B.length();
        int repeat = (nb + na - 1) / na;
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < repeat; ++i) sb.append(A);
        String rA = sb.toString();
        if (rA.indexOf(B) != -1) return repeat;
        rA += A;
        if (rA.indexOf(B) != -1) return repeat + 1;
        return -1;
    }
}
