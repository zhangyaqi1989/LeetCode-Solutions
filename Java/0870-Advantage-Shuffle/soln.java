class Solution {
    public int[] advantageCount(int[] A, int[] B) {
        Arrays.sort(A);
        int n = A.length;
        int[][] order = new int[n][2];
        for(int i = 0; i < n; ++i) {
            order[i][0] = B[i];
            order[i][1] = i;
        }
        Arrays.sort(order, (a, b) -> Integer.compare(a[0], b[0]));
        int[] ans = new int[n];
        int hi = n - 1, i = 0;
        for(int [] p : order) {
            int num = p[0], idx = p[1];
            while (i < n && A[i] <= num) {
                ans[order[hi][1]] = A[i];
                ++i;
                --hi;
            }
            if (i < n) {
                ans[idx] = A[i];
                ++i;
            } else break;
        }
        return ans;
    }
}
