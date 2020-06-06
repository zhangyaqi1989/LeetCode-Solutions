class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        Arrays.sort(nums);
        int sum = 0;
        for(int num : nums) sum += num;
        int cur = 0;
        List<Integer> ans = new ArrayList<>();
        int n = nums.length;
        for(int i = n - 1; i >= 0; --i) {
            cur += nums[i];
            ans.add(nums[i]);
            if (cur > sum - cur) {
                break;
            } 
        }
        return ans;
    }
}
