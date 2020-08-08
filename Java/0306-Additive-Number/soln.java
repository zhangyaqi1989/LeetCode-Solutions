class Solution {
    public boolean isAdditiveNumber(String num) {
        int n = num.length();
        for(int i = 1; i < n; ++i) {
            if(num.charAt(0) == '0' && i > 1) break;
            for(int j = i + 1; j < Math.min(i + 13, n); ++j) {
                if(num.charAt(i) == '0' && j > i + 1) break;
                long a = Long.parseLong(num.substring(0, i));
                long b = Long.parseLong(num.substring(i, j));
                int idx = j;
                while(idx < n) {
                    Long c = a + b;
                    String c_str = Long.toString(c);
                    int len_c = c_str.length();
                    if(idx + len_c <= n && num.substring(idx, idx + len_c).compareTo(c_str) != 0) break;
                    idx += len_c;
                    a = b;
                    b = c;
                }
                if(idx == n) return true;
            }
        }
        return false;
    }
}
