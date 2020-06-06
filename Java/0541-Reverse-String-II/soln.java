class Solution {
    public String reverseStr(String s, int k) {
        StringBuilder sb = new StringBuilder();
        int i = 0, n = s.length();
        while (i < n) {
            String left = s.substring(i, Math.min(i + k, n));
            for(int j = left.length() - 1; j >= 0; --j) {
                sb.append(left.charAt(j));
            }
            i += k;
            if (i >= n) break;
            sb.append(s.substring(i, Math.min(i + k, n)));
            i += k;
        }
        return sb.toString();
    }
}
