class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> idxes = new HashMap<>();
        int n = nums.length;
        for(int i = 0; i < n; ++i) {
            if (idxes.containsKey(nums[i]) && i - idxes.get(nums[i]) <= k) return true;
            idxes.put(nums[i], i);
        }
        return false;
    }
}
