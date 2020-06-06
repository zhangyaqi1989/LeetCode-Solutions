class Solution {
    public int[] gardenNoAdj(int N, int[][] paths) {
        int [][] graph = new int[N][4];
        int [] degrees = new int[N];
        for(int [] row : graph) Arrays.fill(row, -1);
        for(int [] path : paths) {
            int u = path[0], v = path[1];
            --u;
            --v;
            graph[u][degrees[u]++] = v;
            graph[v][degrees[v]++] = u;
        }
        int [] colors = new int [N];
        for(int i = 0; i < N; ++i) {
            if (colors[i] == 0) {
                boolean [] used = new boolean[5];
                for(int j = 0; j < degrees[i]; ++j) {
                    if (colors[graph[i][j]] != 0) used[colors[graph[i][j]]] = true;
                }
                for(int j = 1; j <= 4; ++j) {
                    if (!used[j]) colors[i] = j;
                }
            }
        }
        return colors;
    }
}
