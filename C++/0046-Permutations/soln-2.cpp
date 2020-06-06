class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        const int n = nums.size();
        vector<bool> used(n, false);
        vector<int> path;
        dfs(path, used, nums, ans);
        return ans;
    }
    
private:
    void dfs(vector<int> & path, vector<bool> & used, const vector<int> & nums, vector<vector<int>> & ans) {
        const int n = nums.size();
        if (path.size() == n) {
            ans.push_back(path);
        } else {
            for(int i = 0; i < n; ++i) {
                if (!used[i]) {
                    used[i] = true;
                    path.push_back(nums[i]);
                    dfs(path, used, nums, ans);
                    used[i] = false;
                    path.pop_back();
                }
            }
        }
    }
};
