class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 5 3 4 2 1
        int n = nums.size();
        int k = n - 2;
        for(; k >= 0; --k) {
            if (nums[k] < nums[k + 1]) break;
        }
        if (k < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int l = k + 1;
        for(int j = k + 1; j < n; ++j) {
            if (nums[j] > nums[k]) l = j;
        }
        swap(nums[l], nums[k]);
        reverse(nums.begin() + k + 1, nums.end());
    }
};
