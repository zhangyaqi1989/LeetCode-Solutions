class Solution {
    public int findMaxLength(int[] nums) {
        Map<Integer, Integer> seen = new HashMap<>();
        seen.put(0, -1);
        int n = nums.length;
        int mx = 0, acc = 0;
        for(int i = 0; i < n; ++i) {
            acc += nums[i] == 1 ? 1 : -1;
            if (seen.containsKey(acc)) {
                mx = Math.max(mx, i - seen.get(acc));
            } else {
                seen.put(acc, i);
            }
        }
        return mx;
    }
}
