class Solution {
    public boolean validPalindrome(String s) {
        int n = s.length();
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            if (s.charAt(lo) != s.charAt(hi)) {
                return isPalindrome(s.substring(lo, hi)) || isPalindrome(s.substring(lo + 1, hi + 1)); 
            }
            ++lo;
            --hi;
        }
        return true;
    }
    
    private boolean isPalindrome(String s) {
        int n = s.length();
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            if (s.charAt(lo) != s.charAt(hi)) return false;
            ++lo;
            --hi;
        }
        return true;
    }
}
