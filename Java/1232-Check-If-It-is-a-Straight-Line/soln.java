class Solution {
    public boolean checkStraightLine(int[][] cs) {
        int n = cs.length;
        int x1 = cs[0][0], y1 = cs[0][1];
        int x2 = cs[1][0], y2 = cs[1][1];
        for(int i = 2; i < n; ++i) {
            int x = cs[i][0], y = cs[i][1];
            if ((x - x1) * (y2 - y1) - (x2 - x1) * (y - y1) != 0) return false;
        }
        return true;
    }
}
