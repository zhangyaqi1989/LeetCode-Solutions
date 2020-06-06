class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for(int num : nums) sum += num;
        if (sum % 2 == 1) return false;
        int target = sum / 2;
        Arrays.sort(nums);
        if (nums[nums.length - 1] > target) return false;
        Set<Integer> seen = new HashSet<>();
        seen.add(0);
        int n = nums.length;
        for(int i = n - 1; i >= 0; --i) {
            int num = nums[i];
            Set<Integer> temp = new HashSet<>(seen);
            for(int item : seen) {
                if (item == target || item + num == target) return true;
                temp.add(item + num);
            }
            seen = temp;
        }
        return false;
    }
}
