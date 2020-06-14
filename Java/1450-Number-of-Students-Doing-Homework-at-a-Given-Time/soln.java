class Solution {
    public int busyStudent(int[] startTime, int[] endTime, int queryTime) {
        int n = startTime.length;
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            int s = startTime[i], e = endTime[i];
            if(s <= queryTime && e >= queryTime) ++cnt;
        }
        return cnt;
    }
}
