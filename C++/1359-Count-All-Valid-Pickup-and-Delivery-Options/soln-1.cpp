class Solution {
public:
    int countOrders(int n) {
        const int kMod = 1000000007;
        int f = 1;
        for(int i = 2; i <= n; ++i) {
            int new_f = (long long) i * ((long long) f * (2 * i - 1)) % kMod;
            f = new_f;
        }
        return f;
    }
};
