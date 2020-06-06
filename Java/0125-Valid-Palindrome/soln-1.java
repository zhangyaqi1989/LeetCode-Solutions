class Solution {
    public boolean isPalindrome(String s) {
        String alnum = s.replaceAll("[^A-Za-z0-9]", "").toLowerCase();
        int n = alnum.length();
        int i = 0, j = n - 1;
        while (i < j) {
            if (alnum.charAt(i) != alnum.charAt(j)) return false;
            ++i;
            --j;
        }
        return true;
    }
}
