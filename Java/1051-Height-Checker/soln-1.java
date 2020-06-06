class Solution {
    public int heightChecker(int[] heights) {
        int [] sorted_heights = heights.clone();
        Arrays.sort(sorted_heights);
        int ans = 0;
        for(int i = 0; i < heights.length; ++i) {
            if(heights[i] != sorted_heights[i]) ++ans;
        }
        return ans;
    }
}
