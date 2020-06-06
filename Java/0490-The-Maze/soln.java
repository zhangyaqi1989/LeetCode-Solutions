class Solution {
    public boolean hasPath(int[][] maze, int[] start, int[] destination) {
        int m = maze.length, n = maze[0].length;
        Stack<int []> stack = new Stack<>();
        boolean [][] seen = new boolean[m][n];
        seen[start[0]][start[1]] = true;
        stack.add(start);
        int [] dis = {0, 0, 1, -1};
        int [] djs = {1, -1, 0, 0};
        while (!stack.isEmpty()) {
            int [] node = stack.pop();
            int i = node[0], j = node[1];
            if (i == destination[0] && j == destination[1]) return true;
            for(int k = 0; k < 4; ++k) {
                int di = dis[k], dj = djs[k];
                int newi = i + di, newj = j + dj;
                while (0 <= newi && newi < m && 0 <= newj && newj < n && maze[newi][newj] == 0) {
                    newi += di;
                    newj += dj;
                }
                newi -= di;
                newj -= dj;
                if (i != newi || j != newj) {
                    if (!seen[newi][newj]) {
                        seen[newi][newj] = true;
                        stack.push(new int[] {newi, newj});
                    }
                }
            }
        }
        return false;
    }
}
