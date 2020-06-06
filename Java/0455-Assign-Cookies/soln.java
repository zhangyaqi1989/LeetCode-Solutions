class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int i = 0, j = 0;
        int cnt = 0;
        while (i < g.length) {
            while (j < s.length && s[j] < g[i]) ++j;
            if (j < s.length && g[i] <= s[j]) {
                ++j;
                ++cnt;
            }
            ++i;
        }
        return cnt;
    }
}
