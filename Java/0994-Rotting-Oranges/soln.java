class Solution {
    public int orangesRotting(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int freshes = 0;
        Queue<int []> queue = new LinkedList<>();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) queue.offer(new int []{i, j});
                else if (grid[i][j] == 1) freshes++;
            }
        }
        if (freshes == 0) return 0;
        int steps = 0;
        int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!queue.isEmpty()) {
            ++steps;
            int size = queue.size();
            for(int k = 0; k < size; ++k) {
                int [] point = queue.poll();
                int x = point[0], y = point[1];
                for(int [] dir : dirs) {
                    int newx = x + dir[0];
                    int newy = y + dir[1];
                    if (newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == 1) {
                        grid[newx][newy] = 2;
                        --freshes;
                        queue.offer(new int[]{newx, newy});
                    }
                }
            }
        }
        return freshes == 0 ? steps - 1 : -1;
    }
}
