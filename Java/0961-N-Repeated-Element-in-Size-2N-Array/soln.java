class Solution {
    public int repeatedNTimes(int[] A) {
        int i = 0, j = 0, n = A.length;
        Random rand = new Random();
        while (i == j || A[i] != A[j]) {
            i = rand.nextInt(n);
            j = rand.nextInt(n);
        }
        return A[i];
    }
}
