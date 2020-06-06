class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        int cur = 0;
        int njumps = 0;
        int reach = 0; // if you make a new jump, rightmost you can achieve
        for(int i = 0; i < n; ++i) {
            reach = max(reach, i + nums[i]);
            if(cur >= n - 1) return njumps;
            if(i == cur) {
                njumps += 1;
                cur = reach;
            }
        }
        return njumps;
    }
};
