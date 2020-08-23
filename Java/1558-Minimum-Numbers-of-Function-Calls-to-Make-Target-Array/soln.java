class Solution {
    public int minOperations(int[] nums) {
        int ans = 0, mx_ndoubles = 0;
        for(int num : nums) {
            int ndoubles = 0;
            while(num != 0) {
                if(num % 2 == 1) {
                    ++ans;
                    --num;
                } else {
                    ++ndoubles;
                    num /= 2;
                }
            }
            mx_ndoubles = Math.max(mx_ndoubles, ndoubles);
        }
        return mx_ndoubles + ans;
    }
}
