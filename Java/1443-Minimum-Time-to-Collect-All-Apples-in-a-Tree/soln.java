class Solution {
    public int n_deletes;
    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
        List<Integer> [] tree = new ArrayList[n];
        for(int i = 0; i < n; ++i) tree[i] = new ArrayList<>();
        for(int [] e : edges) {
            int u = e[0], v = e[1];
            tree[u].add(v);
            tree[v].add(u);
        }
        n_deletes = 0;
        Postorder(0, -1, tree, hasApple);
        return (n - 1 - n_deletes) * 2;
    }
    
    private int Postorder(int u, int parent, List<Integer> [] tree, List<Boolean> hasApple) {
        int apples = 0;
        for(int v : tree[u]) {
            if(v != parent) apples += Postorder(v, u, tree, hasApple);
        }
        if(hasApple.get(u)) apples += 1;
        if(apples == 0 && parent != -1) n_deletes += 1;
        return apples;
    }
}
