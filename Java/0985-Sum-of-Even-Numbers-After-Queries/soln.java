class Solution {
    public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
        // sum of even values
        int even = 0;
        for(int num : A) {
            if(num % 2 == 0) even += num;
        }
        int n = queries.length;
        int [] ans = new int [n];
        int i = 0;
        for(int [] q : queries) {
            int val = q[0], index = q[1];
            if (A[index] % 2 == 0) even -= A[index];
            A[index] += val;
            if (A[index] % 2 == 0) even += A[index];
            ans[i++] = even;
        }
        return ans;
    }
}
