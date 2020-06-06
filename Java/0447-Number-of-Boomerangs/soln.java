ass Solution {
    public int numberOfBoomerangs(int[][] points) {
        int ans = 0, n = points.length;
        for(int i = 0; i < n; ++i) {
            Map<Integer, Integer> counter = new HashMap<>();
            for(int j = 0; j < n; ++j) {
                if (i == j) continue;
                int dis = computeDistance(points[i], points[j]);
                counter.put(dis, counter.getOrDefault(dis, 0) + 1);
            }
            for(int cnt : counter.values()) ans += cnt * (cnt - 1);
        }
        return ans;
    }
    
    public int computeDistance(int [] p1, int [] p2) {
        int dx = p1[0] - p2[0];
        int dy = p1[1] - p2[1];
        return dx * dx + dy * dy;
    }
}
