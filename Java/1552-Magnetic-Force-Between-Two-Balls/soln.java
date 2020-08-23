class Solution {
    public int maxDistance(int[] position, int m) {
        Arrays.sort(position);
        int lo = 1;
        int hi = position[position.length - 1] - position[0];
        while(lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if(Valid(position, m, mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
    
    private boolean Valid(int[] position, int m, int d) {
        int pre = (int) -1e9;
        int cnt = 0;
        for(int p : position) {
            if(p - pre >= d) {
                pre = p;
                if(++cnt == m) return true;
            }
        }
        return false;
    }
}
