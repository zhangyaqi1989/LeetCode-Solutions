class Solution {
    public String minInteger(String num, int k) {
        char [] chars = num.toCharArray();
        int n = chars.length;
        for(int i = 0; i < n; ++i) {
            char mn = chars[i];
            int mn_idx = i;
            for(int j = i + 1; j < Math.min(n, i + k + 1); ++j) {
                if(chars[j] < mn) {
                    mn = chars[j];
                    mn_idx = j;
                }
            }
            if(mn != chars[i]) {
                for(int j = mn_idx; j > i; --j) {
                    char temp = chars[j];
                    chars[j] = chars[j - 1];
                    chars[j - 1] = temp;
                }
                k -= (mn_idx - i);
                if(k == 0) break;
            }
        }
        return String.valueOf(chars);
    }
}
