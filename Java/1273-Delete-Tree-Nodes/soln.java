class Solution {
    public int removed = 0;
    public int deleteTreeNodes(int nodes, int[] parent, int[] value) {
        List<Integer> [] tree = new ArrayList[nodes];
        for(int i = 0; i < nodes; ++i) tree[i] = new ArrayList<>();
        for(int i = 0; i < nodes; ++i) {
            if (parent[i] != -1) tree[parent[i]].add(i);
        }
        removed = 0;
        postOrder(tree, value, 0);
        return nodes - removed;
    }
    
    private int[] postOrder(List<Integer>[] tree, int [] value, int node) {
        int count = 1, sum = value[node];
        for(int child : tree[node]) {
            int [] p = postOrder(tree, value, child);
            count += p[0];
            sum += p[1];
        }
        if (sum == 0) {
            removed += count;
            count = 0;
        }
        return new int[] {count, sum};
    }
    
}
