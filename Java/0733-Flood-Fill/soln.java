class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int m = image.length, n = image[0].length;
        int startColor = image[sr][sc];
        boolean [][] visited = new boolean[m][n];
        for(int i = 0; i < m; ++i) Arrays.fill(visited[i], false);
        dfs(image, sr, sc, startColor, newColor, visited);
        return image;
    }
    
    public void dfs(int [][] image, int r, int c, int startColor, int newColor, boolean [][] visited) {
        if (r < 0 || r >= image.length || c < 0 || c >= image[0].length || visited[r][c] || image[r][c] != startColor) return;
        visited[r][c] = true;
        image[r][c] = newColor;
        dfs(image, r - 1, c, startColor, newColor, visited);
        dfs(image, r + 1, c, startColor, newColor, visited);
        dfs(image, r, c - 1, startColor, newColor, visited);
        dfs(image, r, c + 1, startColor, newColor, visited);
    }
}
