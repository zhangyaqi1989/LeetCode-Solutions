class Solution {
    public int totalHammingDistance(int[] nums) {
        int n = nums.length;
        int [] bits = new int[32];
        for(int num : nums) {
            for(int i = 0; i < 32; ++i) {
                if ((num >> i) % 2 == 1) ++bits[i];
            }
        }
        int res = 0;
        for(int cnt : bits) {
            res += cnt * (n - cnt);
        }
        return res;
    }
}
