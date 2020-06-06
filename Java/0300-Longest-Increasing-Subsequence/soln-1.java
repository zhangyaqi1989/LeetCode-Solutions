class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] tails = new int[n];
        int len = 0;
        for(int num : nums) {
            int i = Arrays.binarySearch(tails, 0, len, num);
            // System.out.println(i);
            if (i < 0) i = -(i + 1);
            tails[i] = num;
            if (i == len) ++len;
        }
        return len;
    }
}
