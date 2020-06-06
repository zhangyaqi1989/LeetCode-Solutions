class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        int [] parents = new int[n + 1];
        for(int i = 0; i < n + 1; ++i) parents[i] = i;
        for(int [] e : edges) {
            int x = e[0], y = e[1];
            int rx = find(x, parents);
            int ry = find(y, parents);
            if (rx == ry) return e;
            else parents[rx] = ry;
        }
        return new int [] {0, 0};
    }
    
    public int find(int x, int [] parents) {
        if (parents[x] == x) return x;
        else {
            parents[x] = find(parents[x], parents);
            return parents[x];
        }
    }
}
