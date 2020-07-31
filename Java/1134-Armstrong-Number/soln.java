class Solution {
    public boolean isArmstrong(int N) {
        String str_N = Integer.toString(N);
        int k = str_N.length();
        int memo_N = N;
        long ans = 0;
        while(N > 0) {
            int d = N % 10;
            ans += Math.pow(d, k);
            N /= 10;
        }
        return ans == memo_N;
    }
}
