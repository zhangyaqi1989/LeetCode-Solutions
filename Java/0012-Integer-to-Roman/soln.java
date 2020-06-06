class Solution {
    public String intToRoman(int num) {
        String[] symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int[] units = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int n = units.length;
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; ++i) {
            String symbol = symbols[i];
            int unit = units[i];
            if (num >= unit) {
                for(int j = 0; j < num / unit; ++j) sb.append(symbol);
                num %= unit;
            }
            if (num == 0) return sb.toString();
        }
        return sb.toString();
    }
}
