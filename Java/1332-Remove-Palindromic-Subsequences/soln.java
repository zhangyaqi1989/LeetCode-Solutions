class Solution {
    public int removePalindromeSub(String s) {
        if (s.isEmpty()) return 0;
        int n = s.length(), lo = 0, hi = n - 1;
        while (lo < hi) {
            if (s.charAt(lo) != s.charAt(hi)) return 2;
            ++lo;
            --hi;
        }
        return 1;
    }
}
