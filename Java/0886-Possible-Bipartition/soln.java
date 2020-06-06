class Solution {
    public boolean possibleBipartition(int N, int[][] dislikes) {
        int [] colors = new int[N + 1];
        Arrays.fill(colors, -1);
        List<Integer> [] graph = new ArrayList [N + 1];
        for(int i = 1; i < N + 1; ++i) {
            graph[i] = new ArrayList<>();
        }
        for(int [] dislike : dislikes) {
            int a = dislike[0], b = dislike[1];
            graph[a].add(b);
            graph[b].add(a);
        }
        for(int i = 1; i <= N; ++i) {
            if (colors[i] == -1) {
                colors[i] = 0;
                if (!dfs(i, colors, graph)) return false;
            }
        }
        return true;
    }
    public boolean dfs(int start, int[] colors, List<Integer>[] graph) {
        for(int nei : graph[start]) {
            if (colors[nei] == -1) {
                colors[nei] = 1 - colors[start];
                if (!dfs(nei, colors, graph)) return false;
            } else {
                if (colors[nei] == colors[start]) return false;
            }
        }
        return true;
    }
}
