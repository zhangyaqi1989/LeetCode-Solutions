class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
        int n = position.length;
        int[][] pairs = new int[n][2];
        for(int i = 0; i < n; ++i) {
            pairs[i][0] = target - position[i];
            pairs[i][1] = speed[i];
        }
        Arrays.sort(pairs, (a, b) -> (a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]));
        int cnt = 0;
        double time = -1.0;
        for(int i = 0; i < n; ++i) {
            double temp = (double) pairs[i][0] / pairs[i][1];
            if (temp > time) {
                time = temp;
                ++cnt;
            }
        }
        return cnt;
    }
}
