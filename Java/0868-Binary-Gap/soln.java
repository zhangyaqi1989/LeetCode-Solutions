class Solution {
    public int binaryGap(int N) {
        int i = 0, ans = 0, pre = -1;
        while (N != 0) {
            if (N % 2 == 1) {
                if (pre != -1) {
                    ans = Math.max(ans, i - pre);
                }
                pre = i;
            }
            ++i;
            N /= 2;
        }
        return ans;
    }
}
