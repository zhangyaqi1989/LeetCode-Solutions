class Solution {
    public int minOperations(int n) {
        int target = n;
        int sum = 0;
        for(int i = 0; i < n / 2; ++i) {
            sum += target - (2 * i + 1);
        }
        return sum;
    }
}
