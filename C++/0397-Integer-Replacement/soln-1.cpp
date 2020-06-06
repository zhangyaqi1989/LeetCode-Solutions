class Solution {
public:
    int integerReplacement(int n) {
        unordered_map<long, int> memo;
        return Helper(n, &memo);
    }
    
private:
    
    int Helper(long n, unordered_map<long, int> * memo) {
        if (n == 1) return 0;
        auto it = memo->find(n);
        if (it != memo->end()) return it->second;
        int ans = -1;
        if (n % 2 == 0) ans = Helper(n / 2, memo) + 1;
        else ans = min(Helper(n + 1LL, memo), Helper(n - 1LL, memo)) + 1;
        memo->insert({n, ans});
        return ans;
    }
};
