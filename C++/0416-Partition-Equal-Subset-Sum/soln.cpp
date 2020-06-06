class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        sort(nums.rbegin(), nums.rend());
        map<int, bool> memo;
        memo[0] = true;
        return helper(memo, nums, 0, target);
    }
    
    bool helper(map<int, bool> & memo, vector<int> & nums, int idx, int target) {
        if (memo.find(target) != memo.end()) return memo[target];
        if (target < 0) return false;
        if (idx == nums.size()) {
            return target == 0;
        }
        if (target == 0) {
            return true;
        } else {
            bool ans = false;
            for(int i = idx; i < nums.size(); ++i) {
                if (helper(memo, nums, i + 1, target - nums[i])) {
                    ans = true;
                    break;
                }
            }
            memo[target] = ans;
            return ans;
        }
        
    }
};
