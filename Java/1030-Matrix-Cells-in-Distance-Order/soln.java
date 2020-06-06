class Solution {
    public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
        boolean [][] seen = new boolean[R][C];
        List<int[]> ans = new ArrayList<>();
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] {r0, c0});
        int [] drs = {0, 0, 1, -1};
        int [] dcs = {1, -1, 0, 0};
        seen[r0][c0] = true;
        while (!q.isEmpty()) {
            int [] node = q.poll();
            int r = node[0], c = node[1];
            ans.add(new int [] {r, c});
            for(int k = 0; k < 4; ++k) {
                int newr = r + drs[k], newc = c + dcs[k];
                if (0 <= newr && newr < R && 0 <= newc && newc < C && !seen[newr][newc]) {
                    seen[newr][newc] = true;
                    q.add(new int[] {newr, newc});
                }
            }
        }
        
        return ans.toArray(new int [R * C][]);
    }
}
