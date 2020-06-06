ass Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<>();
        if (matrix.length == 0 || matrix[0].length == 0) return ans;
        int m = matrix.length, n = matrix[0].length;
        int up = 0, down = m - 1, left = 0, right = n - 1;
        int r = 0, c = 0, dr = 0, dc = 1;
        while (ans.size() < m * n) {
            ans.add(matrix[r][c]);
            int nr = r + dr, nc = c + dc;
            if (nc > right) {
                ++up;
                dr = 1;
                dc = 0;
            } else if (nc < left) {
                --down;
                dr = -1;
                dc = 0;
            } else if (nr > down) {
                --right;
                dr = 0;
                dc = -1;
            } else if (nr < up) {
                ++left;
                dr = 0;
                dc = 1;
            }
            r += dr;
            c += dc;
        }
        return ans;
    }
}
