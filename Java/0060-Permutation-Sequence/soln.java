class Solution {
    public String getPermutation(int n, int k) {
        String digits = "123456789";
        digits = digits.substring(0, n);
        String ans = "";
        int units = 1;
        --k;
        for(int i = 2; i < n; ++i) units *= i;
        for(int i = 0; i < n; ++i) {
            int q = k / units;
            ans += digits.charAt(q);
            k %= units;
            if (i < n - 1) units /= (n - 1 - i);
            digits = digits.substring(0, q) + digits.substring(q + 1);
        }
        return ans;
    }
}
