class NumArray {

    public NumArray(int[] nums) {
        this.nums = nums.clone();
        int n = nums.length;
        tree = new int [n + 1];
        for(int i = 0; i < n; ++i) {
            add(i + 1, nums[i]);
        }
    }
    
    public void update(int i, int val) {
        add(i + 1, val - nums[i]);
        nums[i] = val;
    }
    
    public int sumRange(int i, int j) {
        return sum(j + 1) - sum(i);
    }
    
    private int [] nums;
    private int [] tree;
    private int lowbit(int x) {
        return x & (-x); 
    }
    
    private void add(int idx, int val) {
        while (idx < tree.length) {
            tree[idx] += val;
            idx += lowbit(idx);
        }
    }
    
    private int sum(int idx) {
        int ans = 0;
        while (idx > 0) {
            ans += tree[idx];
            idx -= lowbit(idx);
        }
        return ans;
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
