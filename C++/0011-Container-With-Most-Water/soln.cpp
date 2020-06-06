class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int l = 0;
        int r = height.size() - 1;
        while (l < r)
        {
            res = max(res, min(height[r], height[l]) * (r - l));
            if (height[l] <= height[r])
                ++l;
            else
                --r;
        }
        return res;
    }
};