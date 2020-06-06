class Solution {
    public boolean checkPerfectNumber(int num) {
        int ans = 0;
        for(int i = 1; i * i <= num; ++i) {
            if (num % i == 0) {
                if (i == num / i) ans += i;
                else ans += i + num / i;
            }
        }
        return num > 0 && ans == (2 * num);
    }
}
