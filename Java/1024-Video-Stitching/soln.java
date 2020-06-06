class Solution {
    public int videoStitching(int[][] clips, int T) {
        Arrays.sort(clips, (a, b) -> (a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]));
        int i = 0, n = clips.length;
        int start = 0, end = T;
        while (i < n && clips[i][1] < start) {
            ++i;
        }
        int cnt = 0;
        while (start < end) {
            int [] best = {-1, -1};
            while (i < n && clips[i][0] <= start) {
                if (clips[i][1] > best[1]) {
                    best[0] = clips[i][0];
                    best[1] = clips[i][1];
                }
                ++i;
            }
            
            if (best[1] == -1) return -1;
            ++cnt;
            start = best[1];
        }
        return cnt;
    }
}
