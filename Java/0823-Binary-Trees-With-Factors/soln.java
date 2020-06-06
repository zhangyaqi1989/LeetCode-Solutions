class Solution {
    public int numFactoredBinaryTrees(int[] A) {
        Arrays.sort(A);
        Map<Integer, Long> tree = new HashMap<>();
        int n = A.length;
        long ans = 0L;
        int mod = 1000000000 + 7;
        for(int i = 0; i < n; ++i) {
            long cnt = 1;
            for(int j = 0; j < i; ++j) {
                if (A[i] % A[j] == 0 && tree.containsKey(A[i] / A[j]))
                    cnt = (cnt + tree.get(A[j]) * tree.get(A[i] / A[j])) % mod;
            }
            tree.put(A[i], cnt);
        }
        for(long v : tree.values()) ans = (ans + v) % mod;
        return (int) ans;
    }
}
