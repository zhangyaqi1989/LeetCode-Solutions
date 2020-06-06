class Solution {
    public int findShortestSubArray(int[] nums) {
        final int N = 50000;
        int [] counter = new int [N];
        int [] starts = new int [N];
        int [] ends = new int [N];
        int mx = 0;
        for(int i = 0; i < nums.length; ++i) {
            int num = nums[i];
            mx = Math.max(mx, ++counter[num]);
            if (counter[num] == 1) starts[num] = i;
            ends[num] = i;
        }
        int ans = N + 1;
        for(int i = 0; i < N; ++i) {
            if(counter[i] == mx && ends[i] - starts[i] < ans) {
                ans = ends[i] - starts[i];
            }
        }
        return ans + 1;
    }
}
