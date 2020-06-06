class Solution {
public:
    int trap(vector<int>& height) {
        int wall = 0, ans = 0, n = height.size();
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            wall = min(height[lo], height[hi]);
            while (lo < hi && wall >= height[lo]) {
                ans += wall - height[lo++];
            }
            while (lo < hi && wall >= height[hi]) {
                ans += wall - height[hi--];
            }
            
        }
        return ans;
    }
};
