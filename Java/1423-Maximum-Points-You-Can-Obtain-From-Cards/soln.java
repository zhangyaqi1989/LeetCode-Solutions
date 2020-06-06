class Solution {
    public int maxScore(int[] nums, int k) {
        int n = nums.length;
        List<Integer> pres = new ArrayList<>();
        List<Integer> sufs = new ArrayList<>();
        pres.add(0);
        sufs.add(0);
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            pres.add(pres.get(pres.size() - 1) + nums[i]);
        }
        for(int i = n - 1; i >= 0; --i) {
            sufs.add(sufs.get(sufs.size() - 1) + nums[i]);
        }
        for(int left = 0; left <= k; ++left) {
            ans = Math.max(ans, pres.get(left) + sufs.get(k - left));
        }
        return ans;
    }
}
