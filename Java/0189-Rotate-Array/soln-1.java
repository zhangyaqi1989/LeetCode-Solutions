class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k %= n;
        if(k == 0) return;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
    
    private void reverse(int [] nums, int lo, int hi) {
        while(lo < hi) {
            int temp = nums[lo];
            nums[lo] = nums[hi];
            nums[hi] = temp;
            ++lo;
            --hi;
        }
    }
}
