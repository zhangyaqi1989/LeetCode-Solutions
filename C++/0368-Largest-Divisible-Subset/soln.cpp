class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        vector<int> sub;
        helper(nums, 0, sub, ans);
        return ans;
    }
    
    void helper(vector<int> & nums, int idx, vector<int> & sub, vector<int> & ans) {
        int n = nums.size();
        if (sub.size() > ans.size()) ans = sub;
        if (n - idx + sub.size() < ans.size()) return;
        for(int i = idx; i < n; ++i) {
            if (sub.empty() || nums[i] % sub.back() == 0) {
                sub.push_back(nums[i]);
                helper(nums, i + 1, sub, ans);
                sub.pop_back();
            }
        }
    }
};
