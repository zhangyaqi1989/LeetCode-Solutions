class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (nums.size() < 4 || sum % 4 != 0) return false;
        vector<int> subs(4, 0);
        sort(nums.begin(), nums.end(), greater<int>());
        return helper(nums, subs, 0, sum / 4);
    }
    bool helper(vector<int> & nums, vector<int> subs, int idx, int target) {
        if (idx == nums.size()) return true;
        for(int i = 0; i < 4; ++i) {
            if(subs[i] + nums[idx] > target) continue;
            subs[i] += nums[idx];
            if (helper(nums, subs, idx + 1, target))
                return true;
            subs[i] -= nums[idx];
        }
        return false;
    }
};
