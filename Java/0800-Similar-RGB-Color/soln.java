class Solution {
    public String similarRGB(String color) {
        String digits = "0123456789abcdef";
        String ans = "#";
        for(int i = 1; i < 7; i += 2) {
            int num = Integer.parseInt(color.substring(i, i + 2), 16);
            int idx = 0, diff = num;
            for(int j = 1; j < 16; ++j) {
                if (Math.abs(num - (16 * j + j)) < diff) {
                    diff = Math.abs(num - (16 * j + j));
                    idx = j;
                }
            }
            ans += digits.charAt(idx);
            ans += digits.charAt(idx);
        }
        return ans;
    }
}
