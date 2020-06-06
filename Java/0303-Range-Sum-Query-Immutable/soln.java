class NumArray {
    
    private int [] prefix;

    public NumArray(int[] nums) {
        int n = nums.length;
        prefix = new int [n + 1];
        for(int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    
    public int sumRange(int i, int j) {
        return prefix[j + 1] - prefix[i];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
