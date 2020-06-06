class Solution {
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int cnt = 1, idx = 0, n = nums.size();
        for(int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                int r = rand() % cnt;
                if (r == 0) idx = i;
                ++cnt;
            }
        }
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
