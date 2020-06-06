class Solution {
    public boolean isPowerOfThree(int n) {
        if (n <= 0) return false;
        double temp = Math.rint(Math.log(n) / Math.log(3));
        return Math.pow(3, (int) temp) == n;
    }
}
