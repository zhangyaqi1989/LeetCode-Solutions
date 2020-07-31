class Solution {
    public String toHexspeak(String num) {
        String chars = "OIXXXXXXXXABCDEF";
        StringBuilder sb = new StringBuilder();
        long val = Long.parseLong(num);
        while(val > 0) {
            char ch = chars.charAt((int)(val % 16));
            if(ch == 'X') return "ERROR";
            sb.append(ch);
            val /= 16;
        }
        return sb.reverse().toString();
    }
}
