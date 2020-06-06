class Solution {
    public int maxChunksToSorted(int[] arr) {
        // [1,0,2,3,4]
        // greedy
        int n = arr.length;
        int mx = Integer.MIN_VALUE;
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            mx = Math.max(mx, arr[i]);
            if (mx <= i) ++cnt;
        }
        return cnt;
    }
}
