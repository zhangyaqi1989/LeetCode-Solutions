class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> ans;
        vector<int> cand(nums);
        sort(cand.begin(), cand.end());
        int cnt = 1;
        for(int i = 2; i <= n; ++i) cnt *= i;
        while(cnt-- > 0) {
            ans.push_back(cand);
            next_cand(cand);
        }
        return ans;
    }
    
private:
    void next_cand(vector<int> & nums) {
        const int n = nums.size();
        int j = n - 2;
        for(; j >= 0; --j) {
            if (nums[j] < nums[j + 1]) break;
        }
        if (j < 0) return;
        int l = j + 1;
        for(int i = j + 2; i < n; ++i) {
            if (nums[i] > nums[j]) l = i;
        }
        swap(nums[l], nums[j]);
        reverse(nums.begin() + j + 1, nums.end());
    }
};
