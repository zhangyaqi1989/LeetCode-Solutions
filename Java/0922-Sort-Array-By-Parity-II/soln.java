class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int n = A.length, even = 0, odd = 1;
        while (even < n) {
            while(even < n && A[even] % 2 == 0) even += 2;
            while(odd < n && A[odd] % 2 == 1) odd += 2;
            if (even < n) {
                int temp = A[even];
                A[even] = A[odd];
                A[odd] = temp;
            }
        }
        return A;
    }
}
