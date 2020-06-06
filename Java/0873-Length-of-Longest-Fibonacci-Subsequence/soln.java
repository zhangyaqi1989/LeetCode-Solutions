class Solution {
    public int lenLongestFibSubseq(int[] A) {
        Set<Integer> s = new HashSet<>();
        for(int num : A) s.add(num);
        int mx = 0, n = A.length;
        for(int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                int a = A[i], b = A[j];
                int cur = 2;
                while (s.contains(a + b)) {
                    int c = a + b;
                    a = b;
                    b = c;
                    ++cur;
                }
                mx = Math.max(mx, cur);
            }
        }
        return mx < 3 ? 0 : mx;
    }
}
