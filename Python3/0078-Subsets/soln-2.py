class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        search(nums, sub, ans, 0);
        return ans;
    }
    
    void search(vector<int> & nums, vector<int> & sub, vector<vector<int>> & ans, int idx) {
        if (idx == nums.size()) ans.push_back(sub);
        else {
            sub.push_back(nums[idx]);
            search(nums, sub, ans, idx + 1);
            sub.pop_back();
            search(nums, sub, ans, idx + 1);
        }
    }
};
