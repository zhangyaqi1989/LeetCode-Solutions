class Solution {
    public boolean isMajorityElement(int[] nums, int target) {
        int cnt = 0;
        for(int num : nums) {
            if(num == target) ++cnt;
        }
        return cnt > nums.length / 2;
    }
}
