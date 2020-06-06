class Solution {
    public int findCircleNum(int[][] M) {
        Set<Integer> seen = new HashSet<>();
        int n = M.length;
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if (!seen.contains(i)) {
                dfs(seen, M, i);
                ++cnt;
            }
        }
        return cnt;
    }
    
    public void dfs(Set<Integer> seen, int[][] M, int cur) {
        if (!seen.contains(cur)) {
            seen.add(cur);
            int [] row = M[cur];
            for(int i = 0; i < row.length; ++i) {
                if (row[i] == 1)
                    dfs(seen, M, i);
            }
        }
    }
}
