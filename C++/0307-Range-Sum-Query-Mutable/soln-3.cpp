class NumArray {
public:
    NumArray(vector<int>& nums) {
        const int kN = nums.size();
        nums_ = nums;
        n_ = kN + 1;
        tree_.assign(n_, 0);
        for(int i = 0; i < kN; ++i) {
            Add(i + 1, nums[i]);
        }
    }
    
    void update(int i, int val) {
        if (nums_[i] != val) {
            Add(i + 1, val - nums_[i]);
            nums_[i] = val;
        }
    }
    
    int sumRange(int i, int j) {
        return Sum(j + 1) - Sum(i);
    }
    
    
private:
    static inline int Lowbit(int x) {
        return x & (-x);
    }
    
    void Add(int idx, int val) {
        while(idx < n_) {
            tree_[idx] += val;
            idx += Lowbit(idx);
        }
    }
    
    int Sum(int idx) {
        int ans = 0;
        while(idx > 0) {
            ans += tree_[idx];
            idx -= Lowbit(idx);
        }
        return ans;
    }
    
    vector<int> tree_;
    vector<int> nums_;
    int n_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
