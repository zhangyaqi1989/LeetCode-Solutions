class Solution {
    public int minFlips(int a, int b, int c) {
        int cnt = 0;
        for(int i = 0; i < 32; ++i) {
            int ci = (c & (1 << i)) != 0 ? 1 : 0;
            int ai = (a & (1 << i)) != 0 ? 1 : 0;
            int bi = (b & (1 << i)) != 0 ? 1 : 0;
            if (ci == 0) {
                cnt += ai + bi;
            } else {
                if (ai == 0 && bi == 0) ++cnt;
            }
        }
        return cnt;
    }
}
