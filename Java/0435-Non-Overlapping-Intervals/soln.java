class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        // find the minimum number of intervals you need to remove
        // How much can
        Arrays.sort(intervals, (a, b) -> (a[1] == b[1] ? a[0] - b[0] : a[1] - b[1]));
        int lo = Integer.MIN_VALUE;
        int cnt = 0;
        for(int [] interval : intervals) {
            int s = interval[0], e = interval[1];
            if(lo <= s) {
                lo = e;
                ++cnt;
            }
        }
        return intervals.length - cnt;
    }
}
