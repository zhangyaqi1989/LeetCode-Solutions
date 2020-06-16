class TreeAncestor {
    private int [][] table;
    private int height;

    public TreeAncestor(int n, int[] parent) {
        height = 20;
        table = new int[n][height];
        for(int i = 0; i < n; ++i) {
            Arrays.fill(table[i], -1);
            table[i][0] = parent[i];
        }
        for(int i = 1; i < height; ++i) {
            for(int node = 0; node < n; ++node) {
                int j = table[node][i - 1];
                if (j != -1) table[node][i] = table[j][i - 1];
            }
        }
    }
    
    public int getKthAncestor(int node, int k) {
        for(int i = 0; i < height; ++i) {
            if((k & (1 << i)) != 0) node = table[node][i];
            if(node == -1) break;
        }
        return node;
    }
}

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor obj = new TreeAncestor(n, parent);
 * int param_1 = obj.getKthAncestor(node,k);
 */
