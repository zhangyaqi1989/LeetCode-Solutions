class Solution {
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        List<String> ans = new ArrayList<>();
        long miss = lower;
        for(int num : nums) {
            if (num == miss) {
                miss = num + 1L;
            } else if (num > miss) {
                ans.add(rangeToString(miss, num - 1));
                miss = num + 1L;
            }
        }
        if (miss <= upper) ans.add(rangeToString(miss, upper));
        return ans;
    }
    
    public String rangeToString(long lo, long hi) {
        if (lo == hi) return Long.toString(lo);
        return Long.toString(lo) + "->" + Long.toString(hi);
    }
}
