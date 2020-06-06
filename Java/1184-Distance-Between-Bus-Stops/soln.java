class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int sum = 0;
        int d = 0, n = distance.length;
        if (start > destination) {
            int temp = start;
            start = destination;
            destination = temp;
        }
        for(int i = 0; i < n; ++i) {
            sum += distance[i];
            if (i >= start && i < destination) d += distance[i];
        }
        return Math.min(d, sum - d);
    }
}
