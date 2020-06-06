/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
class Solution {
    public int[] findRightInterval(Interval[] intervals) {
        // use TreeMap
        TreeMap<Integer, Integer> m = new TreeMap<>();
        int n = intervals.length;
        for(int i = 0; i < n; ++i) {
            m.put(intervals[i].start, i);
        }
        int[] ans = new int[n];
        for(int i = 0; i < n; ++i) {
            Map.Entry<Integer, Integer> ceil = m.ceilingEntry(intervals[i].end);
            if (ceil == null) {
                ans[i] = -1;
            } else {
                ans[i] = ceil.getValue();
            }
        }
        return ans;
    }
}
