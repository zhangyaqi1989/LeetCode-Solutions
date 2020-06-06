class Solution {
    public int countDigitOne(int n) {
        if (n <= 0) return 0;
        int unit = 1;
        int right = 0;
        int ans = 0;
        while (n != 0) {
            int digit = n % 10;
            n /= 10;
            ans += n * unit;
            if (digit == 1) ans += right + 1;
            else if (digit > 1) ans += unit;
            right += digit * unit;
            unit *= 10;
        }
        return ans;
    }
}
