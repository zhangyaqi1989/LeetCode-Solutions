class Solution {
    public void wiggleSort(int[] nums) {
        int temp;
        for(int i = 1; i < nums.length; ++i) {
            if (i % 2 == 1) {
                if (nums[i - 1] > nums[i]) {
                    temp = nums[i - 1];
                    nums[i - 1] = nums[i];
                    nums[i] = temp;
                }
            } else {
                if (nums[i - 1] < nums[i]) {
                    temp = nums[i - 1];
                    nums[i - 1] = nums[i];
                    nums[i] = temp;
                }
            }
        }
    }
}