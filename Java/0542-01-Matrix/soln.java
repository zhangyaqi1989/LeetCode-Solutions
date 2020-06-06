class Solution {
    public int[][] updateMatrix(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        Queue<int []> frontier = new LinkedList<>();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] = Integer.MAX_VALUE;
                } else {
                    frontier.add(new int[] {i, j});
                }
            }
        }
        int[] dis = {0, 0, 1, -1};
        int[] djs = {1, -1, 0, 0};
        while (!frontier.isEmpty()) {
            int [] node = frontier.poll();
            int i = node[0], j = node[1];
            for(int k = 0; k < 4; ++k) {
                int newi = i + dis[k], newj = j + djs[k];
                if (0 <= newi && newi < m && 0 <= newj && newj < n && matrix[newi][newj] > matrix[i][j] + 1) {
                    frontier.add(new int[] {newi, newj});
                    matrix[newi][newj] = matrix[i][j] + 1;
                } 
            }
        }
        return matrix;
    }
}
