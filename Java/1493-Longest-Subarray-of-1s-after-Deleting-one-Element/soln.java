class Solution {
    public int longestSubarray(int[] nums) {
        int zeros = 0;
        int lo = 0, ans = 0;
        int n = nums.length;
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 0) ++zeros;
            while(zeros > 1) {
                if(nums[lo] == 0) --zeros;
                ++lo;
            }
            ans = Math.max(ans, i - lo);
        }
        return ans;
    }
}
