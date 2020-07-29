class Solution {
    public String stringShift(String s, int[][] shift) {
        int left_shift = 0;
        for(int [] p : shift) {
            int d = p[0], v = p[1];
            if(d == 0) left_shift += v;
            else left_shift -= v;
        }
        int n = s.length();
        left_shift %= n;
        if(left_shift < 0) left_shift += n;
        return s.substring(left_shift) + s.substring(0, left_shift);
    }
}
