class Solution {
public:
    bool canIWin(int mx, int target) {
        if ((1 + mx) * mx / 2 < target) return false;
        if (target == 0) return true;
        unordered_map<int, int> memo;
        return helper(mx, target, 0, memo) == 1;
    }
    
    int helper(int mx, int target, int state, unordered_map<int, int> & memo) {
        if (memo.find(state) != memo.end()) return memo[state];
        int ans;
        if (target <= 0) {
            ans = 2;
        } else {
            for(int i = 1; i <= mx; ++i) {
                if ((state & (1 << i)) == 0) {
                    if (helper(mx, target - i, state | (1 << i), memo) == 2) {
                        memo[state] = 1;
                        return 1;
                    }
                }
            }
            ans = 2;
        }
        memo[state] = ans;
        return ans;
    }
};
