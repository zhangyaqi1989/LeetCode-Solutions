class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> sub;
        helper(nums, 0, sub, ans);
        return ans;
    }
    
    void helper(vector<int> & nums, int idx, vector<int> & sub, vector<vector<int>> & ans) {
        int n = nums.size();
        ans.push_back(sub);
        for(int i = idx; i < n; ++i) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            sub.push_back(nums[i]);
            helper(nums, i + 1, sub, ans);
            sub.pop_back();
        }
    }
};
