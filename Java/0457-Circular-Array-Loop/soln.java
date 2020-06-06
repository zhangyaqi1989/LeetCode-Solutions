class Solution {
    public boolean circularArrayLoop(int[] nums) {
        int mn = 2000;
        int n = nums.length;
        for(int i = 0; i < n; ++i) {
            int mark = mn + i;
            int num = nums[i];
            int j = i;
            while (nums[j] < mn && num * nums[j] > 0 && nums[j] % n != 0) {
                int jump = nums[j];
                nums[j] = mark;
                j = (j + jump) % n;
                if (j < 0) j += n;
            }
            if (nums[j] == mark) return true;
        }
        return false;
    }
}
