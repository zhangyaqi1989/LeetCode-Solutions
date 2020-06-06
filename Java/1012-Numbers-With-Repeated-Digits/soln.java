class Solution {
    public int numDupDigitsAtMostN(int N) {
        int M = N + 1;
        List<Integer> digits = new ArrayList<>();
        while(M > 0) {
            digits.add(0, M % 10);
            M /= 10;
        }
        int n = digits.size();
        int uniques = 0;
        for(int i = 1; i < n; ++i) uniques += 9 * pick(9, i - 1);
        boolean [] used = new boolean[10];
        for(int i = 0; i < n; ++i) {
            int start = i == 0 ? 1 : 0;
            for(int y = start; y < digits.get(i); ++y) {
                if (used[y]) continue;
                uniques += pick(9 - i, n - 1 - i);
            }
            if (used[digits.get(i)]) break;
            used[digits.get(i)] = true;
        }
        return N - uniques;
    }
    
    public int pick(int m, int n) {
        int ans = 1;
        for(int i = 0; i < n; ++i) {
            ans *= m;
            --m;
        }
        return ans;
    }
}
