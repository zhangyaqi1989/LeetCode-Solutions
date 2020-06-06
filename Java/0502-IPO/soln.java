class Solution {
    public int findMaximizedCapital(int k, int W, int[] Profits, int[] Capital) {
        int n = Profits.length;
        int [][] cps = new int [n][2];
        for(int i = 0; i < n; ++i) {
            cps[i][0] = Capital[i];
            cps[i][1] = Profits[i];
        }
        Arrays.sort(cps, (a, b) -> (a[0] - b[0]));
        PriorityQueue<Integer> projects = new PriorityQueue<>();
        int idx = 0;
        for(int i = 0; i < k; ++i) {
            while (idx < n && W >= cps[idx][0]) projects.offer(-cps[idx++][1]);
            if (!projects.isEmpty()) W -= projects.poll();
            else break;
        }
        return W;
    }
}
