class Solution {
    public boolean PredictTheWinner(int[] nums) {
        int [][] memo = new int[21][21];
        for(int [] row : memo) Arrays.fill(row, -1);
        int total = 0;
        for(int num : nums) total += num;
        return compute_score(total, nums, 0, nums.length - 1, memo) >= total / 2.0;
    }
    
    int compute_score(int total, int [] nums, int s, int e, int[][] memo) {
        if (s > e) return 0;
        if (memo[s][e] != -1) return memo[s][e];
        int left = total - compute_score(total - nums[s], nums, s + 1, e, memo);
        int right = total - compute_score(total - nums[e], nums, s, e - 1, memo);
        memo[s][e] = Math.max(left, right);
        return memo[s][e];
    }
}
