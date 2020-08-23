class Solution {
    public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
        int [] indegrees = new int [n];
        for(List<Integer> edge : edges) {
            int u = edge.get(0), v = edge.get(1);
            ++indegrees[v];
        }
        List<Integer> ans = new ArrayList<>();
        for(int u = 0; u < n; ++u) {
            if(indegrees[u] == 0) {
                ans.add(u);
            }
        }
        return ans;
    }
}
