class Solution {
    public int[] singleNumber(int[] nums) {
        int diff = 0;
        for(int num : nums) diff ^= num;
        diff &= -diff;
        int a = 0, b = 0;
        for(int num : nums) {
            if ((num & diff) == 0) a ^= num;
            else b ^= num;
        }
        return new int[] {a, b};
    }
}
