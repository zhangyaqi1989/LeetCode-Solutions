class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int n = nums.length;
        int [] accs = new int [n + 1];
        for(int i = 1; i <= n; ++i) accs[i] = accs[i - 1] + nums[i - 1];
        double mx = -300000000;
        for(int i = k; i <= n; ++i) {
            mx = Math.max(mx, accs[i] - accs[i - k]);
        }
        return mx / k;
    }
}
