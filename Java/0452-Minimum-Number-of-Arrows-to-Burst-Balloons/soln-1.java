class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (a, b)->(a[1] - b[1]));
        int cnt = 0;
        int lo = Integer.MIN_VALUE;
        boolean is_start = true;
        for(int [] point : points) {
            int s = point[0], e = point[1];
            if (is_start || s > lo) {
                ++cnt;
                lo = e;
                is_start = false;
            }
        }
        return cnt;
    }
}
