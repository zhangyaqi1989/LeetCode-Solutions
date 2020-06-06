class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        int[][] pairs = new int[n][2];
        for(int i = 0; i < n; ++i) {
            pairs[i][0] = nums[i];
            pairs[i][1] = i;
        }
        Arrays.sort(pairs, (a, b) -> Integer.compare(a[0], b[0]));
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int s = pairs[lo][0] + pairs[hi][0];
            if (s == target) return new int[] {pairs[lo][1], pairs[hi][1]};
            else if (s < target) ++lo;
            else --hi;
        }
        return new int[] {-1, -1};
    }
}
