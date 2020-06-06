class Solution {
    public int maxSubArrayLen(int[] nums, int k) {
        int mx = 0;
        Map<Integer, Integer> seen = new HashMap<>();
        seen.put(0, -1);
        int n = nums.length;
        int acc = 0;
        for(int i = 0; i < n; ++i) {
            acc += nums[i];
            if (seen.containsKey(acc - k)) {
                mx = Math.max(mx, i - seen.get(acc - k));
            }
            if (!seen.containsKey(acc)) {
                seen.put(acc, i);
            }
        }
        return mx;
    }
}
