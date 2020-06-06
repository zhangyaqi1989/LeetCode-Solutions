class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> seen = new HashMap<>();
        seen.put(0, 1);
        int cur = 0, cnt = 0;
        for(int num : nums) {
            cur += num;
            cnt += seen.getOrDefault(cur - k, 0);
            seen.put(cur, seen.getOrDefault(cur, 0) + 1);
        }
        return cnt;
    }
}
