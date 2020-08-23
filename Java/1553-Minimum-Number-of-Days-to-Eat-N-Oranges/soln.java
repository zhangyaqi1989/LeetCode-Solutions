class Solution {
    private Map<Integer, Integer> memo;
    public int minDays(int n) {
        memo = new HashMap<>();
        return solve(n);
    }

    private int solve(int n) {
        if(n <= 1) return n;
        if(memo.containsKey(n)) return memo.get(n);
        int ans = 1 + Math.min(n % 2 + solve(n / 2), n % 3 + solve(n / 3));
        memo.put(n, ans);
        return ans;
    }
}
