class Solution {
    public boolean isBoomerang(int[][] points) {
        int [] es = {computeDistance2(points, 0, 1), computeDistance2(points, 1, 2), computeDistance2(points, 2, 0)};
        Arrays.sort(es);
        int a = es[0], b = es[1], c = es[2];
        return a > 0 && Math.sqrt(a) + Math.sqrt(b) > Math.sqrt(c);
    }
    
    private int computeDistance2(int [][] points, int i, int j) {
        return (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
    }
}
