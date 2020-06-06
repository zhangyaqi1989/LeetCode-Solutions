class NumArray {
public:
    NumArray(vector<int>& nums) {
        const int N = nums.size();
        size_ = N + 1;
        nums_ = nums;
        tree_.assign(size_, 0);
        for(int i = 0; i < N; ++i) {
            add(i + 1, nums[i]);
        }
    }
    
    void update(int i, int val) {
        if (nums_[i] != val) {
            add(i + 1, val - nums_[i]);
            nums_[i] = val;
        }
    }
    
    int sumRange(int i, int j) {
        return sum(j + 1) - sum(i);
    }
    
private:
    static inline int lowbit(int x) {return x & (-x);}

    void add(int idx, int val) {
        while (idx < size_) {
            tree_[idx] += val;
            idx += lowbit(idx);
        }
    }
    
    int sum(int idx) {
        int ans = 0;
        while (idx > 0) {
            ans += tree_[idx];
            idx -= lowbit(idx);
        }
        return ans;
    }
    
    vector<int> nums_;
    vector<int> tree_;
    int size_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
