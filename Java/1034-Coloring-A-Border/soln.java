class Solution {
    public int[][] colorBorder(int[][] grid, int r0, int c0, int color) {
        if (grid[r0][c0] == color) return grid;
        int R = grid.length, C = grid[0].length;
        Set<String> colored = new HashSet<>();
        Stack<int []> stk = new Stack<>();
        stk.push(new int [] {r0, c0});
        colored.add(r0 + " " + c0);
        int old_color = grid[r0][c0];
        grid[r0][c0] = color;
        int [] dirs = {1, 0, -1, 0, 1};
        while (!stk.isEmpty()) {
            int [] node = stk.pop();
            int r = node[0], c = node[1];
            for(int k = 0; k < 4; ++k) {
                int newr = r + dirs[k], newc = c + dirs[k + 1];
                if (0 <= newr && newr < R && 0 <= newc && newc < C && grid[newr][newc] == old_color) {
                    colored.add(newr + " " + newc);
                    stk.push(new int [] {newr, newc});
                    grid[newr][newc] = color;
                }
            }
        }
        List<int []> inner = new ArrayList<>();
        for(String node : colored) {
            boolean is_inner = true;
            String[] rc = node.split(" ");
            int r = Integer.parseInt(rc[0]), c = Integer.parseInt(rc[1]);
            for(int k = 0; k < 4; ++k) {
                int newr = r + dirs[k], newc = c + dirs[k + 1];
                if (newr < 0 || newr >= R || newc < 0 || newc >= C || !colored.contains(newr + " " + newc)) {
                    is_inner = false;
                    break;
                }
            }
            if (is_inner) inner.add(new int [] {r, c});
        }
        for(int [] node : inner) {
            grid[node[0]][node[1]] = old_color;
        }
        return grid;
    }
}
