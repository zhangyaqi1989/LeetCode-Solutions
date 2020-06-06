class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> diags;
        int h = nums.size();
        for(int i = 0; i < h; ++i) {
            int w = nums[i].size();
            for(int j = 0; j < w; ++j) {
                diags[i + j].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        for(auto & p : diags) {
            for(auto it = p.second.rbegin(); it < p.second.rend(); ++it) {
                ans.push_back(*it);
            }
        }
        return ans;
    }
};
