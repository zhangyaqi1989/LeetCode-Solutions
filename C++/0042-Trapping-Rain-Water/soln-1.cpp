class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            if (height[lo] <= height[hi]) {
                ans += max(0, height[lo] - height[lo + 1]);
                height[lo + 1] = max(height[lo], height[lo + 1]);
                ++lo;
            } else {
                ans += max(0, height[hi] - height[hi - 1]);
                height[hi - 1] = max(height[hi - 1], height[hi]);
                --hi;
            }
        }
        return ans;
    }
};
