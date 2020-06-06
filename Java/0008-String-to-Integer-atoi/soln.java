class Solution {
    public int myAtoi(String str) {
        int i = 0, n = str.length();
        long ans = 0;
        while(i < n && str.charAt(i) == ' ') ++i;
        if (i == n) return 0;
        int sign = 1;
        if (str.charAt(i) == '+' || str.charAt(i) == '-') {
            if (str.charAt(i) == '-') sign = -1;
            ++i;
        }
        while (i < n && Character.isDigit(str.charAt(i))) {
            ans = ans * 10 + (str.charAt(i++) - '0');
            if (sign * ans > Integer.MAX_VALUE) return Integer.MAX_VALUE;
            if (sign * ans < Integer.MIN_VALUE) return Integer.MIN_VALUE;
        }
        return sign * ((int) ans);
    }
}
