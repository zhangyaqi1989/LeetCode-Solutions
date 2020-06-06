class Solution {
    public int minAreaRect(int[][] points) {
        Map<Integer, Set<Integer>> x_to_ys = new HashMap<>();
        for(int [] point : points) {
            int x = point[0], y = point[1];
            if (!x_to_ys.containsKey(x)) x_to_ys.put(x, new HashSet<>());
            x_to_ys.get(x).add(y);
        }
        int ans = Integer.MAX_VALUE;
        for(int [] p1 : points) {
            for(int [] p2 : points) {
                int x1 = p1[0], y1 = p1[1], x2 = p2[0], y2 = p2[1];
                if (x1 == x2 || y1 == y2) continue;
                if (x_to_ys.get(x1).contains(y2) && x_to_ys.get(x2).contains(y1)) {
                    ans = Math.min(ans, Math.abs(x1 - x2) * Math.abs(y1 - y2));
                }
            }
        }
        return ans == Integer.MAX_VALUE ? 0 : ans;
    }
}
