class Solution {
    public boolean lemonadeChange(int[] bills) {
        int c5 = 0, c10 = 0;
        for(int b : bills) {
            if (b == 5) ++c5;
            else if (b == 10) {
                ++c10;
                if (--c5 < 0) return false;
            } else {
                int val = 15;
                if(c10 > 0) {
                    --c10;
                    val -= 10;
                }
                int need = val / 5;
                if(c5 < need) {
                    return false;
                }
                c5 -= need;
            }
        }
        return true;
    }
}
