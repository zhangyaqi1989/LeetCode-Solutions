class Solution {
    public int numDupDigitsAtMostN(int N) {
        int M = N + 1;
        List<Integer> digits = new ArrayList<>();
        do {
            digits.add(M % 10);
            M /= 10;
        } while (M != 0);
        Collections.reverse(digits);
        int uniques = 0;
        int cur = 9, n = digits.size();
        for(int i = 1; i < n; ++i) {
            uniques += cur;
            cur *= 10 - i;
        }
        boolean [] seen = new boolean[10];
        for(int i = 0; i < n; ++i) {
            int d = digits.get(i);
            int start = i == 0 ? 1 : 0;
            for(int x = start; x < d; ++x) {
                if (seen[x]) continue;
                uniques += func(9 - i, n - 1 - i);
            }
            if (seen[d]) break;
            seen[d] = true;
        }
        return N - uniques;
    }
    
    private int func(int m, int n) {
        return n == 0 ? 1 : m * func(m - 1, n - 1);
    }
}
