class Solution {
    public int minimumCost(int N, int[][] connections) {
        Arrays.sort(connections, (a, b) -> (a[2] - b[2]));
        int [] parents = new int[N];
        for(int i = 0; i < N; ++i) parents[i] = i;
        int minCost = 0;
        int cnt = 0;
        for(int [] connect : connections) {
            int u = connect[0] - 1, v = connect[1] - 1, w = connect[2];
            int ru = find(u, parents), rv = find(v, parents);
            if (ru != rv) {
                parents[ru] = rv;
                ++cnt;
                minCost += w;
                if (cnt == N - 1) return minCost;
            }
        }
        return (cnt == N - 1) ? minCost : -1;
    }
    
    private int find(int x, int [] parents) {
        return (parents[x] == x) ? x : (parents[x] = find(parents[x], parents));
    }
}
