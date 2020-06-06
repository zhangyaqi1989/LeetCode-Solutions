class Solution {
    public int[] plusOne(int[] digits) {
        int idx = -1, n = digits.length;
        for(int i = 0; i < n; ++i) {
            if (digits[i] != 9) idx = i;
        }
        for(int cur = idx + 1; cur < n; ++cur) digits[cur] = 0;
        if (idx == -1) {
            int[] ans = new int[n + 1];
            ans[0] = 1;
            for(int i = 0; i < n; ++i) ans[i + 1] = digits[i];
            return ans;
            
        } else {
            int[] ans = new int[n];
            for(int i = 0; i < n; ++i) {
                if (i == idx) ans[i] = digits[i] + 1;
                else ans[i] = digits[i];
            }
            return ans;
        }
    }
}
