class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        int n = intervals.length;
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            int a = intervals[i][0], b = intervals[i][1];
            boolean covered = false;
            for(int j = 0; j < n; ++j) {
                if (i == j) continue;
                int c = intervals[j][0], d = intervals[j][1];
                if (c <= a && b <= d) {
                    covered = true;
                    break;
                }
            }
            if(!covered) ++cnt;
        }
        return cnt;
    }
}
