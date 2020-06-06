class Solution {
    public int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        int seed;
        if (K % 2 == 0) {
            seed = kthGrammar(N - 1, K / 2);
        } else {
            seed = kthGrammar(N - 1, (K + 1) / 2);
        }
        if (seed == 0) {
            if (K % 2 == 0) return 1;
            return 0;
        } else {
            if (K % 2 == 0) return 0;
            return 1;
        }
    }
}
