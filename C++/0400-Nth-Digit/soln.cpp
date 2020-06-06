class Solution {
public:
    int findNthDigit(int n) {
        // 1-digit number: 9
        // 2-digit number: 10 - 100: 90
        // 3-digit number: 100 - 1000: 900
        long long unit = 9;
        int d = 1;
        while (n > 0) {
            long long num = unit * d;
            if (n > num) {
                n -= num;
            } else {
                --n;
                int q = n / d;
                int r = n % d;
                string s = to_string((int) pow(10, d - 1) + q);
                return s[r] - '0';
            }
            unit *= 10;
            ++d;
        }
        return 0;
        
    }
};
