class Solution {
    public String breakPalindrome(String s) {
        StringBuilder sb = new StringBuilder(s);
        int idx = 0, n = s.length();
        while(idx < n / 2) {
            if (sb.charAt(idx) != 'a') {
                sb.setCharAt(idx, 'a');
                return sb.toString();
            }
            ++idx;
        }
        if(n != 1) {
            sb.setCharAt(n - 1, 'b');
        } else {
            return "";
        }
        return sb.toString();
    }
}
