class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> ans;
        int cur = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.rbegin(), nums.rend());
        for(int num : nums) {
            cur += num;
            ans.push_back(num);
            if (cur > sum - cur) {
                break;
            }
        }
        return ans;
    }
};
