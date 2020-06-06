class Solution {
    public String licenseKeyFormatting(String S, int K) {
        StringBuilder sb = new StringBuilder();
        for(char ch : S.toCharArray()) {
            if(ch != '-') sb.append(Character.toUpperCase(ch));
        }
        if(sb.length() == 0) return "";
        String chars = sb.toString();
        int n = chars.length();
        int q = n / K, r = n % K;
        StringBuilder ans = new StringBuilder();
        int lo = 0;
        if (r != 0) {
            ans.append(chars.substring(0, r));
            lo = r;
        }
        for(int i = 0; i < q; ++i) {
            if (!(i == 0 && r == 0)) ans.append("-");
            ans.append(chars.substring(lo, lo + K));
            lo += K;
        }
        return ans.toString();
    }
}
