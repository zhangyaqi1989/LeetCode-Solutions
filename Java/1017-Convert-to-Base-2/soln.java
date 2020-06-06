class Solution {
    public String baseNeg2(int N) {
        if (N == 0) return "0";
        String ans = "";
        while (N != 0) {
            int r = N % (-2);
            N /= (-2);
            if (r < 0) {
                r += 2;
                ++N;
            }
            ans = Integer.toString(r) + ans;
        }
        return ans;
    }
}
