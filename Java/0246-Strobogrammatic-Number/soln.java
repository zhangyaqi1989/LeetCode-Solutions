class Solution {
    public boolean isStrobogrammatic(String num) {
        String bads = "23457";
        for(char ch : num.toCharArray()) {
            if (bads.indexOf(ch) != -1) return false;
        }
        int n = num.length();
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            char ch = num.charAt(lo);
            char new_ch = ch;
            if (ch == '6') new_ch = '9';
            else if (ch == '9') new_ch = '6';
            if (new_ch != num.charAt(hi)) return false;
            ++lo;
            --hi;
        }
        return true;
    }
}
