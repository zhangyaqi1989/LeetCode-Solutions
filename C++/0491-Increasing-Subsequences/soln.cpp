class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> path;
        set<vector<int>> ans;
        helper(nums, 0, ans, path);
        vector<vector<int>> ret(ans.begin(), ans.end());
        return ret;
    }
    
    void helper(vector<int> & nums, int idx, set<vector<int>> & ans, vector<int> & path) {
        int n = nums.size();
        if(idx == n) {
            if (path.size() > 1) ans.insert(path);
        } else {
            if (path.size() > 1) ans.insert(path);
            for(int i = idx; i < n; ++i) {
                // if (i > idx && nums[i] == nums[i - 1]) continue;
                if (path.empty() || nums[i] >= path.back()) {
                    path.push_back(nums[i]);
                    helper(nums, i + 1, ans, path);
                    path.pop_back();
                }
            }
        }
    }
};
