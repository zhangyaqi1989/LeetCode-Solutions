class Solution {
    public int[] constructRectangle(int area) {
        int upper = (int) Math.sqrt(area);
        int w = upper;
        for(; w >= 1; --w) {
            if (area % w == 0) break;
        }
        return new int[] {area / w, w};
    }
}
