class Solution {
    public int countNegatives(int[][] grid) {
        int cnt = 0, n = grid[0].length;
        for(int [] row : grid) {
            int lo = 0, hi = n;
            while(lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (row[mid] >= 0) lo = mid + 1;
                else hi = mid;
            }
            cnt += n - lo;
        }
        return cnt;
    }
}
