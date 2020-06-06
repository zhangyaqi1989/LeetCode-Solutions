class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 3; ++i)
        {
            if(i > 0 && nums[i - 1] == nums[i]) continue;
            for(int j = i + 1; j < nums.size() - 2; ++j)
            {
                if(j > i + 1 && nums[j - 1] == nums[j]) continue;
                int target2 = target - nums[i] - nums[j];
                int l = j + 1;
                int r = nums.size() - 1;
                while (l < r)
                {
                    int s = nums[l] + nums[r];
                    if (s == target2)
                    {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1]) ++l;
                        while (l < r && nums[r] == nums[r - 1]) --r;
                        ++l;
                        --r;
                    } else if (s < target2) ++l;
                    else --r;
                }
            }
        }
        return ans;
        
    }
};