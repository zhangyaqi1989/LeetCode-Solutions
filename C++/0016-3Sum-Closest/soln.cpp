class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; ++i)
        {
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                int diff = nums[i] + nums[l] + nums[r] - target;
                if(diff == 0) return target;
                if(abs(diff) < abs(min_diff)) min_diff = diff;
                if (diff < 0) ++l;
                else --r;
            }
        }
        return target + min_diff;
    }
};