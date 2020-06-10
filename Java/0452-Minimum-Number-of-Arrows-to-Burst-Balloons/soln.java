class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (a, b)->(a[1] - b[1]));
        int cnt = 0;
        long lo = Long.MIN_VALUE;
        for(int [] point : points) {
            int s = point[0], e = point[1];
            if (s > lo) {
                ++cnt;
                lo = e;
            }
        }
        return cnt;
    }
}
