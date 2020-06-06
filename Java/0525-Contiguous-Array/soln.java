class Solution {
    public int findMaxLength(int[] nums) {
        Map<Integer, Integer> m = new HashMap<>();
        m.put(0, -1);
        int n = nums.length, cnt = 0, ans = 0;
        for(int i = 0; i < n; ++i) {
            int num = nums[i];
            cnt += (num == 1 ? 1 : -1);
            if (m.get(cnt) == null) {
                m.put(cnt, i);
            } else {
                ans = Math.max(ans, i - m.get(cnt));
            }
        }
        return ans;
    }
}
