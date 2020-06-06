class Solution {
    
    public int integerReplacement(int n) {
        Map<Integer, Integer> memo = new HashMap<>();
        return helper(memo, n);
    }
    
    public int helper(Map<Integer, Integer> memo, int n) {
        if (n == 1) return 0;
        if (memo.containsKey(n)) return memo.get(n);
        int ans;
        if (n % 2 == 1) {
            ans = 2 + Math.min(helper(memo, n / 2), helper(memo, n / 2 + 1));
        } else {
            ans = 1 + helper(memo, n / 2);
        }
        memo.put(n, ans);
        return ans;
    }
}
