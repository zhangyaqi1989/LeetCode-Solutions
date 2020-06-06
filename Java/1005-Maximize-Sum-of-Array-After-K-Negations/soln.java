class Solution {
    public int largestSumAfterKNegations(int[] A, int K) {
        Arrays.sort(A);
        int n = A.length;
        for(int i = 0; i < n && K > 0; ++i, --K) {
            if (A[i] < 0) A[i] = -A[i];
            else break;
        }
        int mn = Integer.MAX_VALUE;
        int ans = 0;
        for(int num : A) {
            ans += num;
            if (num < mn) mn = num;
        }
        return ans - (K % 2) * 2 * mn;
    }
}
