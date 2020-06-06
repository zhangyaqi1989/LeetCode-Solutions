class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0;
        int res = INT_MIN;
        for(auto num : nums)
        {
            cur = max(cur + num, num);
            res = max(res, cur);
        }
        return res;
    }
};