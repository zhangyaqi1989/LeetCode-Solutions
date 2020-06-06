class Solution {
    public boolean canIWin(int mx, int target) {
        if (target <= mx) return true;
        if ((1 + mx) * mx / 2 < target) return false;
        Map<Integer, Integer> memo = new HashMap<>();
        return helper(mx, target, 0, memo) == 1;
    }
    

    public int helper(int mx, int target, int state, Map<Integer, Integer> memo) {
        if (memo.containsKey(state)) return memo.get(state);
        int ans = 2;
        if (target > 0) {
            for (int i = mx; i >= 1; --i) {
                if ((state & (1 << i)) == 0) {
                    if (helper(mx, target - i, state | (1 << i), memo) == 2) {
                        ans = 1;
                        break;
                    }
                }
            }
        }
        memo.put(state, ans);
        return ans;
    }
}
