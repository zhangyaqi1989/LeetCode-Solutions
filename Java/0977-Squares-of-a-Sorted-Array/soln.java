class Solution {
    public int[] sortedSquares(int[] A) {
        int n = A.length;
        int [] res = new int [n];
        for(int i = 0; i < n; ++i) {
            res[i] = A[i] * A[i];
        }
        Arrays.sort(res);
        return res;
    }
}
