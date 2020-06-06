class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        long sum = 0L;
        for(int num : nums) sum += num;
        return (int) ((long) (0 + n) * (n + 1) / 2 - sum);
    }
}
