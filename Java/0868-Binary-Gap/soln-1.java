class Solution {
    public int binaryGap(int N) {
        int pre = -1, ans = 0, idx = 0;
        while (N != 0) {
            if (N % 2 == 1) {
                if (pre != -1) ans = Math.max(ans, idx - pre);
                pre = idx;
            }
            N >>= 1;
            ++idx;
        }
        return ans;
    }
}
