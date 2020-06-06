class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if (farthest < i) return false;
            farthest = max(farthest, i + nums[i]);
            if (farthest >= n - 1) return true;
        }
        return farthest >= n - 1;
    }
};
