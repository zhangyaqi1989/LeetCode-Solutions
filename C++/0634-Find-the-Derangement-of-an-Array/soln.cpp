class Solution {
public:
    int findDerangement(int n) {
        // f(n) = (n - 1) * (f(n - 2) + f(n - 1))
        // f(1) = 0, f(2) = 1, f(3) = 2
        if (n <= 3) return n - 1;
        int mod = 1e9 + 7;
        long long pre = 1, cur = 2;
        for(int i = 4; i <= n; ++i) {
            int temp = cur;
            cur = ((pre + cur) * (i - 1)) % mod;
            pre = temp;
        }
        return cur;
    }
};
