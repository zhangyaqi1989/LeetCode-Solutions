class Solution {
    public int minDistance(int height, int width, int[] tree, int[] squirrel, int[][] nuts) {
        int tx = tree[0], ty = tree[1], sx = squirrel[0], sy = squirrel[1];
        int repeat = 0;
        for(int [] nut : nuts) repeat += 2 * (Math.abs(nut[0] - tx) + Math.abs(nut[1] - ty));
        int mn = Integer.MAX_VALUE;
        for(int [] nut : nuts) {
            int temp = repeat + Math.abs(nut[0] - sx) + Math.abs(nut[1] - sy) - Math.abs(nut[0] - tx) - Math.abs(nut[1] - ty);
            mn = Math.min(mn, temp);
        }
        return mn;
    }
}
