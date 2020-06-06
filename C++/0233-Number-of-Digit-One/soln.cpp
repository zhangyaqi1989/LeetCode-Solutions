class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        long long unit = 1, ans = 0, right = 0;
        while (n != 0) {
            int d = n % 10;
            n /= 10;
            ans += n * unit;
            if (d == 1) ans += right + 1;
            else if (d > 1) ans += unit;
            right += d * unit;
            unit *= 10;
        }
        return ans;
    }
};
