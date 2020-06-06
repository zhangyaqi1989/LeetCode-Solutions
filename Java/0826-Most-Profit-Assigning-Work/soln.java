class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int n = profit.length;
        int [][] pairs = new int [n][2];
        for(int i = 0; i < n; ++i) {
            pairs[i][0] = difficulty[i];
            pairs[i][1] = profit[i];
        }
        Arrays.sort(pairs, (a, b)->(a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]));
        Arrays.sort(worker);
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int idx = 0;
        int ans = 0;
        int best = 0;
        for(int ability : worker) {
            while(idx < n && pairs[idx][0] <= ability) {
                best = Math.max(best, pairs[idx][1]);
                ++idx;
            }
            ans += best;
        }
        return ans;
    }
}
