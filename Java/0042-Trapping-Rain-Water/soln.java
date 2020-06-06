ass Solution {
    public int trap(int[] height) {
        int boundary = 0, n = height.length;
        int lo = 0, hi = n - 1, ans = 0;
        while (lo < hi) {
            while (lo < hi && height[lo] <= height[hi]) {
                ans += Math.max(0, boundary - height[lo]);
                boundary = Math.max(boundary, height[lo]);
                ++lo;
            }
            while (lo < hi && height[lo] > height[hi]) {
                ans += Math.max(0, boundary - height[hi]);
                boundary = Math.max(boundary, height[hi]);
                --hi;
            }
        }
        return ans;
    }
}
