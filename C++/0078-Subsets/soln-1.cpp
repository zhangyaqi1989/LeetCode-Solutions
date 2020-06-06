class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        dfs(0, nums, sub, ans);
        return ans;
    }
    
private:
    void dfs(int idx, const vector<int> & nums, vector<int> & sub, vector<vector<int>> & ans) {
        if (idx == (int) nums.size()) {
            ans.push_back(sub);
        } else {
            sub.push_back(nums[idx]);
            dfs(idx + 1, nums, sub, ans);
            sub.pop_back();
            dfs(idx + 1, nums, sub, ans);            
        }

    }
};
