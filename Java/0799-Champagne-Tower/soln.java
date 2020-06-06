class Solution {
    public double champagneTower(int poured, int query_row, int query_glass) {
        double [] glasses = new double[100];
        glasses[0] = poured;
        for(int row = 1; row <= query_row; ++row) {
            for(int j = row; j >= 0; --j) {
                glasses[j] = Math.max(0, glasses[j] - 1) / 2;
                if (j > 0) glasses[j] += Math.max(0, glasses[j - 1] - 1) / 2;
            }
        }
        return Math.min(1, glasses[query_glass]);
    }
}
