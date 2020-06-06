class Solution {
    public int twoCitySchedCost(int[][] costs) {
        int n = costs.length;
        int [][]  ps = new int [n][2];
        for(int i = 0; i < n; ++i) {
            ps[i][0] = costs[i][0] - costs[i][1];
            ps[i][1] = i;
        }
        Arrays.sort(ps, (a, b) -> (a[0] - b[0]));
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if (i < n / 2) {
                ans += costs[ps[i][1]][0];
            } else {
                ans += costs[ps[i][1]][1];
            }
        }
        return ans;
    }
}
