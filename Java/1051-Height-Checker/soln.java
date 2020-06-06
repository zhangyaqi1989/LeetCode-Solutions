class Solution {
    public int heightChecker(int[] heights) {
        int [] rhs = heights.clone();
        Arrays.sort(rhs);
        int n = heights.length;
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if (rhs[i] != heights[i]) ++cnt;
        }
        return cnt;
    }
}
