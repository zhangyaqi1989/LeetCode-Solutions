class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        String s = String.valueOf(x);
        String rs = new StringBuffer(s).reverse().toString();
        // System.out.println(rs);
        return s.equals(rs);
    }
}
