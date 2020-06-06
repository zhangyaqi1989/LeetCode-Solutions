class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> memo = new HashMap<>();
        for(int i = 0; i < nums.length; ++i) {
            if (memo.containsKey(nums[i])) {
                return new int[] {memo.get(nums[i]), i};
            }
            memo.put(target - nums[i], i);
        }
        return new int [] {-1, -1};
    }
}
