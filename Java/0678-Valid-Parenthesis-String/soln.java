class Solution {
    public boolean checkValidString(String s) {
        int lo = 0, hi = 0;
        for(char ch : s.toCharArray()) {
            if (ch == '(') {
                ++lo;
                ++hi;
            } else if (ch == '*') {
                --lo;
                ++hi;
            } else {
                --lo;
                --hi;
            }
            lo = Math.max(0, lo);
            if (hi < 0) return false;
        }
        return lo == 0;
    }
}
