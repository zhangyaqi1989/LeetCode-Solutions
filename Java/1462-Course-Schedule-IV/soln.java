class Solution {
    public List<Boolean> checkIfPrerequisite(int n, int[][] prerequisites, int[][] queries) {
        boolean [][] graph = new boolean [n][n];
        for(int i = 0; i < n; ++i) graph[i][i] = true;
        for(int [] e : prerequisites) {
            int u = e[0], v = e[1];
            graph[u][v] = true;
        }
        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    graph[i][j] = graph[i][j] | (graph[i][k] & graph[k][j]);
                }
            }
        }
        List<Boolean> ans = new ArrayList<>();
        for(int [] q : queries) {
            ans.add(graph[q[0]][q[1]]);
        }
        return ans;
    }
}
