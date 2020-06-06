class Solution {
    private Map<String, Integer> memo;
    public int maxSizeSlices(int[] slices) {
        memo = new HashMap<>();
        int mn = slices[0], mn_idx = 0, n = slices.length;
        int [] nums = new int [n];
        for(int i = 0; i < n; ++i) {
            if (slices[i] < mn) {
                mn = slices[i];
                mn_idx = i;
            }
        }
        int idx = 0;
        for(int i = mn_idx; i < n; ++i) {
            nums[idx++] = slices[i];
        }
        for(int i = 0; i < mn_idx; ++i) {
            nums[idx++] = slices[i];
        }
        return dp(n / 3, n - 1, nums);
    }
    
    private int dp(int x, int y, int [] nums) {
        if (x * 2 - 1 > y) return Integer.MIN_VALUE;
        String hash = x + "-" + y;
        if (memo.containsKey(hash)) return memo.get(hash);
        int ans = -1;
        if (x == 1) {
            int mx = -1;
            for(int i = 0; i < y + 1; ++i) {
                if (nums[i] > mx) {
                    mx = nums[i];
                }
            }
            ans = mx;
        } else {
            ans = Math.max(nums[y] + dp(x - 1, y - 2, nums), dp(x, y - 1, nums));
        }
        memo.put(hash, ans);
        return ans;
    }
}
