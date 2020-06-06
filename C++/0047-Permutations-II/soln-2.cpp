class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> init(nums.begin(), nums.end());
        do {
            ans.push_back(nums);
            next_permutation(nums.begin(), nums.end());
        } while (!equal(init.begin(), init.end(), nums.begin()));
        return ans;
    }
};
