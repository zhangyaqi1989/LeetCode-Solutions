class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(houses);
        Arrays.sort(heaters);
        int idx = 0;
        int mx = Integer.MIN_VALUE, n = heaters.length, dist = Integer.MAX_VALUE;
        for(int house : houses) {
            while (idx < n && house >= heaters[idx]) ++idx;
            if (idx == 0) dist = heaters[idx] - house;
            else if (idx < n) dist = Math.min(heaters[idx] - house, house - heaters[idx - 1]);
            else dist = house - heaters[idx - 1];
            // System.out.println(dist);
            mx = Math.max(mx, dist);
        }
        return mx;
    }
}
