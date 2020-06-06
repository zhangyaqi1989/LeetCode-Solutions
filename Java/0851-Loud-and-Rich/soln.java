class Solution {
    public int[] loudAndRich(int[][] richer, int[] quiet) {
        int n = quiet.length;
        ArrayList<Integer>[] graph = new ArrayList[n];
        int[] degrees = new int[n];
        for(int i = 0; i < n; ++i) graph[i] = new ArrayList<>();
        for(int [] ab : richer) {
            int a = ab[0], b = ab[1];
            graph[a].add(b);
            ++degrees[b];
        }
        Stack<Integer> frees = new Stack<>();
        int[] ans = new int[n];
        for(int i = 0; i < n; ++i) {
            if (degrees[i] == 0) frees.push(i);
            ans[i] = i;
        }
        while(!frees.isEmpty()) {
            int node = frees.pop();
            for(int nei : graph[node]) {
                if (quiet[ans[node]] < quiet[ans[nei]]) ans[nei] = ans[node];
                degrees[nei] -= 1;
                if (degrees[nei] == 0) frees.push(nei);
            }
        }
        return ans;
    }
}
