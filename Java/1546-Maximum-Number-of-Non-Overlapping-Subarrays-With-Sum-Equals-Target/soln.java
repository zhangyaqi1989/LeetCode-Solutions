class Solution {
    public int maxNonOverlapping(int[] nums, int target) {
        Set<Integer> seen = new HashSet<>();
        seen.add(0);
        int cur = 0, cnt = 0;
        for(int num : nums) {
            cur += num;
            if(seen.contains(cur - target)) {
                ++cnt;
                seen.clear();
            }
            seen.add(cur);
        }
        return cnt;
    }
}
