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
    public int minMeetingRooms(Interval[] intervals) {
        Map<Integer, Integer> changes = new TreeMap<Integer, Integer>();
        for(Interval interval : intervals) {
            changes.put(interval.start, changes.getOrDefault(interval.start, 0) + 1);
            changes.put(interval.end, changes.getOrDefault(interval.end, 0) - 1);
        }
        int ans = 0, cnt = 0;
        for(Integer time: changes.keySet()) {
            cnt += changes.get(time);
            ans = Math.max(ans, cnt);
        }
        return ans;
    }
}
