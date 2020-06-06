class Solution {
    public void wallsAndGates(int[][] rooms) {
        if (rooms.length == 0 || rooms[0].length == 0) return;
        Queue<int[]> queue = new LinkedList<>();
        final int INF = 2147483647;
        int m = rooms.length, n = rooms[0].length;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) 
                    queue.offer(new int[] {i, j});
            }
        int[] dis = {0, 0, 1, -1};
        int[] djs = {1, -1, 0, 0};
        while (!queue.isEmpty()) {
            int [] node = queue.poll();
            int i = node[0], j = node[1];
            for(int k = 0; k < 4; ++k) {
                int newi = i + dis[k], newj = j + djs[k];
                if (0 <= newi && newi < m && newj >= 0 && newj < n && rooms[newi][newj] == INF) {
                    rooms[newi][newj] = rooms[i][j] + 1;
                    queue.offer(new int[] {newi, newj});
                }
            }
        }
    }
}
