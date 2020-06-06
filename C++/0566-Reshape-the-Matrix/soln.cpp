class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size();
        int n = nums[0].size();
        if (m * n != r * c) return nums;
        vector<vector<int>> ans (r, vector<int>(c, 0));
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                int idx = i * c + j;
                int row = idx / n;
                int col = idx % n;
                ans[i][j] = nums[row][col]; 
            }
        }
        return ans;
    }
};