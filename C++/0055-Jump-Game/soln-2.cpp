class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int n = nums.size();
        int mx = nums[0];
        for(int i = 0; i < n; ++i) {
            if (i > mx) return false;
            mx = max(mx, i + nums[i]);
            if (mx >= n - 1) return true;
        }
        return true;
    }
};
