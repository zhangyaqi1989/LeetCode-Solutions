class Solution {
    public int dominantIndex(int[] nums) {
        int first = -1, second = -1, first_idx = -1;
        for(int i = 0; i < nums.length; ++i) {
            int num = nums[i];
            if (num > first) {
                second = first;
                first = num;
                first_idx = i;
            // exact one largest num
            } else if (num > second) second = num;
        }
        return first >= 2 * second ? first_idx : -1;
    }
}
