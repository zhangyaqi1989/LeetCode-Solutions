class Solution {
public:
    int reverse(int x) {
        int sign = x < 0 ? -1 : 1;
        long long ans = 0;
        if (x < 0) {
            if (x == INT_MIN) return 0;
            else x = -x;
        }
        do {
            ans = ans * 10 + x % 10;
            x /= 10;
        } while (x);
        ans *= sign;
        if (ans > INT_MAX || ans < INT_MIN) return 0;
        return ans;
    }
};
