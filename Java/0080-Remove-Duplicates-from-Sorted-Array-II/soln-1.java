class Solution {
    public int removeDuplicates(int[] nums) {
        int w_idx = 0;
        int lo = 0, n = nums.length;
        for(int i = 0; i < n; ++i) {
            if(nums[i] != nums[lo]) {
                int cnt = Math.min(2, i - lo);
                for(int j = 0; j < cnt; ++j) nums[w_idx++] = nums[lo];
                lo = i;
            }
        }
        int cnt = Math.min(2, n - lo);
        for(int j = 0; j < cnt; ++j) nums[w_idx++] = nums[lo];
        return w_idx;
        
    }
}
