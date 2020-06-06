class Solution {
    public boolean escapeGhosts(int[][] ghosts, int[] target) {
        int t0 = target[0], t1 = target[1];
        int distance = Math.abs(t0) + Math.abs(t1);
        for(int[] ghost : ghosts) {
            if (Math.abs(ghost[0] - t0) + Math.abs(ghost[1] - t1) <= distance)
                return false;
        }
        return true;
    }
}
