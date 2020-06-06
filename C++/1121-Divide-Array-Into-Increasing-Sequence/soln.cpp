class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        const int N = nums.size();
        int cur = 1, mx = 1;
        for(int i = 1; i < N; ++i) {
            if (nums[i - 1] < nums[i]) {
                mx = max(mx, cur);
                cur = 1;
            } else {
                ++cur;
            }
        }
        mx = max(mx, cur);
        return N >= K * mx;
    }
};
