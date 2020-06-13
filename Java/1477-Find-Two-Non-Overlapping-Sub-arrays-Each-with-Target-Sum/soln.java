class Solution {
    public int minSumOfLengths(int[] arr, int target) {
        final int INF = Integer.MAX_VALUE;
        int n = arr.length;
        Map<Integer, Integer> memo = new HashMap<>();
        int [] lefts = new int [n];
        Arrays.fill(lefts, INF);
        int cur = 0;
        memo.put(0, -1);
        for(int i = 0; i < n; ++i) {
            if(i > 0) lefts[i] = lefts[i - 1];
            cur += arr[i];
            if(memo.containsKey(cur - target)) {
                lefts[i] = Math.min(lefts[i], i - memo.get(cur - target));
            }
            memo.put(cur, i);
        }
        memo.clear();
        memo.put(0, n);
        cur = 0;
        int memo_right = INF;
        int ans = INF;
        for(int i = n - 1; i >= 0; --i) {
            int right = memo_right;
            cur += arr[i];
            if(memo.containsKey(cur - target)) {
                right = Math.min(right, memo.get(cur - target) - i);
            }
            if(i > 0 && right != INF && lefts[i - 1] != INF) {
                ans = Math.min(ans, right + lefts[i - 1]);
            }
            memo.put(cur, i);
            memo_right = right;
        }
        return ans == INF ? -1 : ans;
    }
}
