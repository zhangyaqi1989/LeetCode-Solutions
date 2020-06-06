class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        if (houses.length == 0) return 0;
        if (heaters.length == 0) return Integer.MAX_VALUE;
        Arrays.sort(houses);
        Arrays.sort(heaters);
        int ans = Integer.MIN_VALUE, n = heaters.length;
        int min_dis;
        int lo = 0;
        for(int house : houses) {
            while (lo < n && heaters[lo] < house) {
                ++lo;
            }
            if (lo < n) {
                if (lo == 0) min_dis = heaters[lo] - house;
                else min_dis = Math.min(heaters[lo] - house, house - heaters[lo - 1]);
                ans = Math.max(ans, min_dis);
            } else {
                ans = Math.max(ans, houses[houses.length - 1] - heaters[n - 1]);
            }
        }
        return ans;
    }
}
