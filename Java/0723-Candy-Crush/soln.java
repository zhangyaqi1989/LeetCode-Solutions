class Solution {
    public int[][] candyCrush(int[][] board) {
        while (true) {
            if (!process(board)) break;
        }
        return board;
    }
    
    public boolean process(int[][] M) {
        int m = M.length, n = M[0].length;
        Set<Integer> crushes = new HashSet<>();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(j + 2 < n && M[i][j] != 0 && M[i][j] == M[i][j + 1] && M[i][j] == M[i][j + 2]) {
                    crushes.add(i * n + j);
                    crushes.add(i * n + j + 1);
                    crushes.add(i * n + j + 2);
                }
                if(i + 2 < m && M[i][j] != 0 && M[i][j] == M[i + 1][j] && M[i][j] == M[i + 2][j]) {
                    crushes.add(i * n + j);
                    crushes.add((i + 1) * n + j);
                    crushes.add((i + 2) * n + j);
                }
            }
        }
        for(int num : crushes) {
            M[num / n][num % n] = 0;
        }
        for(int j = 0; j < n; ++j) {
            int wi = m - 1;
            for(int i = m - 1; i >= 0; --i) {
                if (M[i][j] != 0) {
                    M[wi--][j] = M[i][j];
                }
            }
            for(int i = wi; i >= 0; --i) {
                M[i][j] = 0;
            }
        }
        return !crushes.isEmpty();
    }
}
