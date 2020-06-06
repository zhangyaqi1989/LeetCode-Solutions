class Solution {
    public int[][] diagonalSort(int[][] mat) {
        Map<Integer, PriorityQueue<Integer>> diags = new HashMap<>();
        int m = mat.length, n = mat[0].length;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                diags.putIfAbsent(i - j, new PriorityQueue<>());
                diags.get(i - j).add(mat[i][j]);
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                mat[i][j] = diags.get(i - j).poll();
            }
        }
        return mat;
    }
}
