class NumArray {
    vector<int> cums;
public:
    NumArray(vector<int> nums) {
        int cur = 0;
        for(auto num : nums) {
            cur += num;
            cums.push_back(cur);
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0) return cums[j];
        else return cums[j] - cums[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
