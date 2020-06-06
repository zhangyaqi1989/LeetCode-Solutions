class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        int ans = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 0; i < nums.size() - 2; ++i)
        {
            // if(i > 0 && nums[i - 1] == nums[i]) continue;
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                int s = nums[i] + nums[l] + nums[r];
                if (s < target)
                {
                    ans += r - l;
                    --r;
                }    
                else ++l;
            }
        }
        return ans;
    }
};