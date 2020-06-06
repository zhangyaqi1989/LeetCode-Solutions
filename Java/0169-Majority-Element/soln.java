class Solution {
    public int majorityElement(int[] nums) {
        int ans = nums[0], cnt = 0;
        for(int num : nums) {
            if (num == ans) {
                ++cnt;
            } else if (cnt == 0) {
                ans = num;
                cnt = 1;
            } else {
                --cnt;
            }
        }
        return ans;
    }
}
