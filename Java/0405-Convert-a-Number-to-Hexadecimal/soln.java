class Solution {
    public String toHex(int num) {
        if (num == 0) return "0";
        String alphas = "0123456789abcdef";
        StringBuilder sb = new StringBuilder();
        while (num != 0) {
            sb.append(alphas.charAt(num & 0xf));
            num >>>= 4;
        }
        return sb.reverse().toString();
    }
}
