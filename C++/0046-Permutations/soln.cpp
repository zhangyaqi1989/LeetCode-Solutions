class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        int cnt = 1;
        for (int i = 1; i <= n; ++i)
            cnt *= i;
        while(cnt--) {
            ans.push_back(nums);
            next_permutation(nums.begin(), nums.end());
        }
        return ans;
    }
};