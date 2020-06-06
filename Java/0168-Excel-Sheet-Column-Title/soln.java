class Solution {
    public String convertToTitle(int n) {
        StringBuilder sb = new StringBuilder();
        while (n != 0) {
            --n;
            int val = n % 26;
            n /= 26;
            sb.append((char)('A' + val));
        }
        return sb.reverse().toString();
    }
}
