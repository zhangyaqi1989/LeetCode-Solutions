class Solution {
    public int rangeSum(int[] nums, int n, int left, int right) {
        ArrayList<Integer> pres = new ArrayList<>();
        pres.add(0);
        ArrayList<Integer> subs = new ArrayList<>();
        int sum = 0;
        for(int num : nums) {
            sum += num;
            for(int val : pres) {
                subs.add(sum - val);
            }
            pres.add(sum);
        }
        Collections.sort(subs);
        final int MOD = 1000000007;
        int ans = 0;
        for(int i = left; i <= right; ++i) {
            ans = (int) (((long) ans + subs.get(i - 1)) % MOD);
        }
        return ans;
    }
}
