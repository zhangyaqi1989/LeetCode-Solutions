class Solution {
    public int minNumberOperations(int[] target) {
        int ans = target[0];
        int pre = target[0];
        int n = target.length;
        for(int i = 1; i < n; ++i) {
            ans += Math.max(0, target[i] - pre);
            pre = target[i];
        }
        return ans;
    }
}
