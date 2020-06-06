class Solution {
    public int[] assignBikes(int[][] workers, int[][] bikes) {
        int nw = workers.length, nb = bikes.length;
        List<int []> tuples = new ArrayList<>();
        for(int i = 0; i < nw; ++i) 
            for(int j = 0; j < nb; ++j) {
                tuples.add(new int[] {Math.abs(workers[i][0] - bikes[j][0]) + Math.abs(workers[i][1] - bikes[j][1]), i, j});
            }
        Collections.sort(tuples, (a, b) -> {if (a[0] == b[0]) {if (a[1] == b[1]) return a[2] - b[2]; else return a[1] - b[1];} else return a[0] - b[0];});
        int [] ans = new int [nw];
        boolean [] wused = new boolean[nw];
        boolean [] bused = new boolean[nb];
        int cnt = 0;
        for(int [] t : tuples) {
            int d = t[0], iw = t[1], ib = t[2];
            if(!wused[iw] && !bused[ib]) {
                wused[iw] = true;
                bused[ib] = true;
                ans[iw] = ib;
                if (++cnt == nw) break;
            }
        }
        return ans;
    }
}
