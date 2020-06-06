class Solution {
    map<int, long> memo;
public:
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (memo.find(n) != memo.end()) return memo[n];
        long ans = 0;
        if (n % 2 == 1) {
            ans = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
        } else {
            ans = 1 + integerReplacement(n / 2);
        }
        // cout << ans << endl;
        memo[n] = ans;
        return ans;
    }
};
