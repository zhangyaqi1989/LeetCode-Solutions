class Solution {
    public int[][] intervalIntersection(int[][] A, int[][] B) {
        List<int []> times = new ArrayList<>();
        int idx = 0, n = B.length;
        for(int [] inta : A) {
            int sa = inta[0], ea = inta[1];
            while (idx < n && B[idx][1] < sa) ++idx;
            while (idx < n && B[idx][0] <= ea) {
                int sb = B[idx][0], eb = B[idx][1];
                times.add(new int[] {Math.max(sa, sb), Math.min(ea, eb)});
                ++idx;
            }
            if(idx > 0) --idx;
        }
        int m = times.size();
        int[][] ans = new int[m][2];
        for(int i = 0; i < m; ++i) {
            ans[i][0] = times.get(i)[0];
            ans[i][1] = times.get(i)[1];
        }
        return ans;
    }
}
