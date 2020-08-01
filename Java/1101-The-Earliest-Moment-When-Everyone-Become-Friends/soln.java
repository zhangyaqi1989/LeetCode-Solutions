class Solution {
    private int [] parents;
    public int earliestAcq(int[][] logs, int N) {
        parents = new int [N];
        for(int i = 0; i < N; ++i) parents[i] = i;
        Arrays.sort(logs, (a, b)->(a[0] - b[0]));
        for(int [] log : logs) {
            int time = log[0], x = log[1], y = log[2];
            int rx = find(x), ry = find(y);
            if(rx != ry) {
                parents[rx] = ry;
                if(--N == 1) return time;
            }
        }
        return -1;
    }
    
    private int find(int x) {
        if(parents[x] == x) return x;
        parents[x] = find(parents[x]);
        return parents[x];
    }
}
