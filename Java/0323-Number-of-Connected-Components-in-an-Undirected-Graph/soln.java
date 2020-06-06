class Solution {
    public int countComponents(int n, int[][] edges) {
        if (n == 0) return 0;
        int[] parents = new int[n];
        for(int i = 0; i < n; ++i) parents[i] = i;
        for(int [] edge : edges) {
            unite(edge[0], edge[1], parents);
        }
        for(int i = 0; i < n; ++i) find(i, parents);
        Set<Integer> s = new HashSet<>();
        for(int i = 0; i < n; ++i) s.add(parents[i]);
        return s.size();
    }
    
    public int find(int x, int[] parents) {
        if (x == parents[x]) return x;
        else {
            int rx = find(parents[x], parents);
            parents[x] = rx;
            return rx;
        }
        // return (x == parents[x]) ? x : parents[x] = find(parents[x], parents);
    }
    
    public void unite(int x, int y, int[] parents) {
        int rx = find(x, parents);
        int ry = find(y, parents);
        if (rx != ry) parents[rx] = parents[ry];
    }
    
    
}
