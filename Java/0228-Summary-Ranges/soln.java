class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> ans = new ArrayList<>();
        int n = nums.length;
        if (n == 0) return ans;
        int lo = nums[0], hi = nums[0];
        for(int i = 1; i < n; ++i) {
            if(hi + 1 == nums[i]) hi += 1;
            else {
                ans.add(toRangeString(lo, hi));
                lo = nums[i];
                hi = nums[i];
            }
        }
        ans.add(toRangeString(lo, hi));
        return ans;
    }
    
    private String toRangeString(int lo, int hi) {
        if (lo == hi) return Integer.toString(lo);
        return Integer.toString(lo) + "->" + Integer.toString(hi);
    }
}
