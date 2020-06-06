class Solution {
    public int maxArea(int h, int w, int[] hs, int[] vs) {
        Arrays.sort(hs);
        Arrays.sort(vs);
        int nh = hs.length, nv = vs.length;
        int max_dh = Math.max(hs[0], h - hs[nh - 1]);
        for(int i = 1; i < nh; ++i) max_dh = Math.max(max_dh, hs[i] - hs[i - 1]);
        int max_dv = Math.max(vs[0], w - vs[nv - 1]);
        for(int i = 1; i < nv; ++i) max_dv = Math.max(max_dv, vs[i] - vs[i - 1]);
        return (int) ((long) max_dh * max_dv % 1000000007);
    }
}
