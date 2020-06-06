class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        else if (n == 1) return 10;
        else {
            n = Math.min(n, 10);
            int[] choice = {9, 8, 7, 6, 5, 4, 3, 2, 1};
            int ans = 10, cur = 9;
            for(int i = 0; i < n - 1; ++i) {
                cur *= choice[i];
                ans += cur;
            }
            return ans;
        }
    }
}
