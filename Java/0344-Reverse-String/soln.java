class Solution {
    public void reverseString(char[] s) {
        int lo = 0, n = s.length, hi = n - 1;
        while (lo < hi) {
            char temp = s[lo];
            s[lo] = s[hi];
            s[hi] = temp;
            ++lo;
            --hi;
        }
    }
}
