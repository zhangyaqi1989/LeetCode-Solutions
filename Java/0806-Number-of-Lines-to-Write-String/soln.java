class Solution {
    public int[] numberOfLines(int[] widths, String S) {
        int nlines = 1, cur = 0;
        for(char ch : S.toCharArray()) {
            int width = widths[ch - 'a'];
            if (cur + width > 100) {
                ++nlines;
                cur = width;
            } else {
                cur += width;
            }
        }
        return new int[] {nlines, cur};
    }
}
