class Solution {
    public boolean isPalindrome(String s) {
        String alnum = s.replaceAll("[^A-Za-z0-9]", "").toLowerCase();
        String rev = new StringBuilder(alnum).reverse().toString();
        return alnum.equals(rev);
    }
}
