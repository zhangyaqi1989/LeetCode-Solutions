class Solution {
    public String toHexspeak(String num) {
        final String digits = "OI23456789ABCDEF";
        long val = Long.parseLong(num);
        StringBuilder sb = new StringBuilder();
        while(val != 0) {
            int d = (int) (val % 16);
            if (d >= 2 && d <= 9) return "ERROR";
            sb.append(digits.charAt(d));
            val /= 16;
        }
        return sb.reverse().toString();
    }
}

