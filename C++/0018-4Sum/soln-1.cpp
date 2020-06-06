class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        const int n = nums.size();
        if (n < 4) return {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1, r = n - 1;
                while (l < r) {
                    int s = nums[i] + nums[j] + nums[l] + nums[r];
                    if (s == target) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l + 1 < r && nums[l + 1] == nums[l]) ++l;
                        while (r - 1 > l && nums[r - 1] == nums[r]) --r;
                        ++l;
                        --r;
                    } else if (s < target) {
                        ++l;
                    } else {
                        --r;
                    }
                }
            }
        }
        return ans;
    }
};
