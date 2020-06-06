class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int [] nums_copy = nums.clone();
        Arrays.sort(nums_copy);
        int n = nums.length;
        int [] ans = new int [n];
        for(int i = 0; i < n; ++i) {
            int num = nums[i];
            int lo = 0, hi = n - 1;
            // first value that is equal or large to num
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (nums_copy[mid] >= num) hi = mid;
                else lo = mid + 1;
            }
            ans[i] = lo;
        }
        return ans;
    }
}
