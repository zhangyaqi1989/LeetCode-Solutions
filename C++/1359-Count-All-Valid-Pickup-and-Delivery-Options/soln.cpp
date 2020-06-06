int memo [505];
const int kMod = 1000000007;

class Solution {
    
public:
    int countOrders(int n) {
        return helper(n);
    }
    
private:
    int helper(int n) {
        if (n == 1) return 1;
        if (memo[n] > 0) return memo[n];
        int ans = (long long) n * ((long long) helper(n - 1) * (2 * n - 1)) % kMod;
        memo[n] = ans;
        return ans;
    }
};
