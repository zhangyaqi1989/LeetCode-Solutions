class Solution {
    public int[] distributeCandies(int m, int n) {
        int [] ans = new int [n];
        for(int i = 0; m > 0; ++i) {
            int give = n * i + 1;
            for(int j = 0; j < n; ++j) {
                if (m <= give) {
                    ans[j] += m;
                    return ans;
                } else {
                    ans[j] += give;
                    m -= give;
                }
                ++give;
            }
        }
        return ans;
    }
}
