class Solution {
    public int findJudge(int N, int[][] trust) {
        int [] out_degrees = new int[N + 1];
        int [] in_degrees = new int[N + 1];
        for(int[] row : trust) {
            int a = row[0], b = row[1];
            out_degrees[a]++;
            in_degrees[b]++;
        }
        for(int i = 1; i <= N; ++i) {
            if (out_degrees[i] == 0 && in_degrees[i] == N - 1)
                return i;
        }
        return -1;
    }
}
