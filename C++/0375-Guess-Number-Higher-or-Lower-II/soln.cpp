class Solution {
    
public:
    map<pair<int, int>, int> memo;
    int getMoneyAmount(int n) {
        memo.clear();
        return count(1, n);
    }
    
    int count(int lo, int hi) {
        if (lo >= hi) return 0;
        if (memo.find({lo, hi}) != memo.end()) return memo[{lo, hi}];
        int ans = INT_MAX;
        for(int x = lo; x < hi; ++x) {
            ans = min(ans, x + max(count(lo, x - 1), count(x + 1, hi)));
        }
        memo[{lo, hi}] = ans;
        return ans;
    }
};
