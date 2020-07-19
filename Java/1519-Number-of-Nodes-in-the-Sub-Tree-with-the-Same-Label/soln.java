class Solution {
    public int[] countSubTrees(int n, int[][] edges, String labels) {
        ArrayList<Integer> [] tree = new ArrayList[n];
        for(int i = 0; i < n; ++i) {
            tree[i] = new ArrayList<>();
        }
        for(int [] edge : edges) {
            int u = edge[0], v = edge[1];
            tree[u].add(v);
            tree[v].add(u);
        }
        int [] ans = new int [n];
        Postorder(0, -1, tree, labels, ans);
        return ans;
    }
    
    private int [] Postorder(int node, int parent, ArrayList<Integer>[] tree, String labels, int [] ans) {
        int [] counter = new int [26];
        for(int nei : tree[node]) {
            if(nei == parent) continue;
            int [] temp = Postorder(nei, node, tree, labels, ans);
            for(int i = 0; i < 26; ++i) {
                counter[i] += temp[i];
            }
        }
        ans[node] = ++counter[labels.charAt(node) - 'a'];
        return counter;
    }
}
