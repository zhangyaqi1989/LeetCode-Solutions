class Solution {
    private Map<String, Integer> memo;
    public int assignBikes(int[][] workers, int[][] bikes) {
        memo = new HashMap<>();
        return dfs(workers, bikes, 0, 0);
    }
    
    public int dfs(int[][] workers, int[][] bikes, int idx, int mask) {
        if (idx == workers.length) return 0;
        if (memo.containsKey(idx + " " + mask)) return memo.get(idx + " " + mask);
        int ans = Integer.MAX_VALUE;
        for(int i = 0; i < bikes.length; ++i) {
            if ((mask & (1 << i)) == 0) {
                ans = Math.min(ans, Math.abs(workers[idx][0] - bikes[i][0]) + Math.abs(workers[idx][1] - bikes[i][1]) + dfs(workers, bikes, idx + 1, mask | (1 << i)));
            }
        }
        memo.put(idx + " " + mask, ans);
        return ans;
    }
}
