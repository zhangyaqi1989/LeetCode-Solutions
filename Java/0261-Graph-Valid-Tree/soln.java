class Solution {
    public boolean validTree(int n, int[][] edges) {
        if (edges.length != n - 1) return false;
        int[] parents = new int[n];
        for(int i = 0; i < n; ++i) parents[i] = i;
        for(int [] edge : edges) {
            int a = edge[0], b = edge[1];
            int ra = find(a, parents), rb = find(b, parents);
            if (ra == rb) return false;
            parents[ra] = parents[rb];
        }
        return true;
    }
    
    public int find(int x, int[] parents) {
        if (x == parents[x]) return x;
        else {
            parents[x] = find(parents[x], parents);
            return parents[x];
        }
    }
}
