class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int l, r;
        l = 0;
        r = height.size() - 1;
        int min_height = 0;
        while(l < r)
        {
            while(l < r && min_height >= height[l])
            {
                ans += min_height - height[l];
                ++l;
            }
            while(l < r && min_height >= height[r])
            {
                ans += min_height - height[r];
                --r;
            }
            min_height = min(height[l], height[r]);
        }
        return ans;
    }
};