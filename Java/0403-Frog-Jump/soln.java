class Solution {
    public boolean canCross(int[] stones) {
        memo = new HashMap<>();
        return helper(stones, 0, 0);
    }
    public boolean helper(int [] stones, int pos, int k) {
        int key = pos | (k << 11);
        if (memo.containsKey(key)) return memo.get(key);
        int n = stones.length;
        for(int i = pos + 1; i < n; ++i) {
            int gap = stones[i] - stones[pos];
            if (gap < k - 1) continue;
            else if (gap > k + 1) {
                memo.put(key, false);
                return false;
            } else {
                if (helper(stones, i, gap)) {
                    memo.put(key, true);
                    return true;
                }
            }
        }
        memo.put(key, pos == n - 1);
        return pos == n - 1;
    }
    private Map<Integer, Boolean> memo;
}
