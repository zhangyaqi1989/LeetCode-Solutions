class Solution {
    public int [] dist;
    public int [] count;
    public int dist0;
    public List<Integer> [] tree;
    public int[] sumOfDistancesInTree(int N, int[][] edges) {
        dist = new int [N];
        count = new int [N];
        Arrays.fill(count, 1);
        tree = new ArrayList[N];
        for (int i = 0; i < N; ++i) tree[i] = new ArrayList<>();
        for (int [] edge : edges) {
            tree[edge[0]].add(edge[1]);
            tree[edge[1]].add(edge[0]);
        }
        dist0 = 0;
        dfs1(0, -1, 0);
        dist[0] = dist0;
        dfs2(0, -1, N);
        // for(int c : count) System.out.println(c);
        return dist;
    }
    
    public void dfs1(int node, int parent, int path) {
        dist0 += path;
        for(int nei : tree[node]) {
            if (nei != parent) {
                dfs1(nei, node, path + 1);
                count[node] += count[nei];
            }
        }
    }
    
    public void dfs2(int node, int parent, int N) {
        for(int nei : tree[node]) {
            if (nei != parent) {
                dist[nei] = dist[node] + N - 2 * count[nei];
                dfs2(nei, node, N);
            }
        }
    }
}
