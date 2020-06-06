class NumArray {
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        tree.assign(n + 1, 0);
        for(int i = 0; i < n; ++i) {
            add(i + 1, nums[i]);
        }
    }
    
    void update(int i, int val) {
        add(i + 1, val - nums[i]);
        nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        return sum(j + 1) - sum(i);
    }
    
private:
    vector<int> nums;
    vector<int> tree;
    
    int lowbit(int x) {
        return x & (-x);
    }
    
    void add(int idx, int val) {
        while (idx < tree.size()) {
            tree[idx] += val;
            idx += lowbit(idx);
        }
    }
    
    int sum(int idx) {
        int ans = 0;
        while (idx > 0) {
            ans += tree[idx];
            idx -= lowbit(idx);
        }
        return ans;
    }

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
