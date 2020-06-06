class Solution {
    public int[] sumZero(int n) {
        int [] ans = new int [n];
        int idx = 0;
        if(n % 2 == 1) ++idx;
        n /= 2;
        for(int j = 1; j <= n; ++j) {
            ans[idx++] = j;
            ans[idx++] = -j;
        }
        return ans;
    }

}
