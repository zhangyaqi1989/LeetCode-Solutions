class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                if(nums[l] + nums[r] > nums[i])
                {
                    ans += r - l;
                    l += 1;
                } else
                {
                    r -= 1;
                }
            }
        }
        return ans;
    }
};