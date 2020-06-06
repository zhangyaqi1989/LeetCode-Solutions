class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int lo = 0, cnt = 0;
        int mx = 0;
        for(int i = 0; i < nums.length; ++i) {
            if (nums[i] == nums[lo]) {
                ++cnt;
            } else {
                if (nums[lo] == 1) mx = Math.max(mx, cnt);
                cnt = 1;
                lo = i;
            }
        }
        if (nums[lo] == 1) mx = Math.max(mx, cnt);
        return mx;
    }
}
