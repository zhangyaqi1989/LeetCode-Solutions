class Solution {
    public int getMoneyAmount(int n) {
        Map<String, Integer> memo = new HashMap<>();
        return count(1, n, memo);
    }
    
    public int count(int lo, int hi, Map<String, Integer> memo) {
        if (lo >= hi) return 0;
        String key = lo + " " + hi;
        if (memo.containsKey(key)) return memo.get(key);
        int ans = Integer.MAX_VALUE;
        for(int x = lo; x < hi; ++x) {
            ans = Math.min(ans, x + Math.max(count(lo, x - 1, memo), count(x + 1, hi, memo)));
        }
        memo.put(key, ans);
        return ans;
    }
}
