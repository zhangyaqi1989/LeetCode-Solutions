class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, end = 0, farthest = 0, n = nums.size();
        for(int i = 0; i < n; ++i) {
            if (end >= n - 1) break;
            farthest = max(farthest, i + nums[i]);
            if (end == i) {
                ++jumps;
                end = farthest;
            }
        }
        return jumps;
    }
};
