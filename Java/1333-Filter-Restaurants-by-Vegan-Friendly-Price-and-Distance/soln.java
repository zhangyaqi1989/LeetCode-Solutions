class Solution {
    public List<Integer> filterRestaurants(int[][] restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        List<int []> pairs = new ArrayList<>();
        for(int [] rest : restaurants) {
            int id = rest[0], r = rest[1], v = rest[2], p = rest[3], d = rest[4];
            if (veganFriendly == 1 && v == 0) continue;
            if (p <= maxPrice && d <= maxDistance) {
                pairs.add(new int [] {-r, -id});
            }
        }
        Collections.sort(pairs, (a, b)->(a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]));
        List<Integer> ans = new ArrayList<>();
        for(int [] p : pairs) ans.add(-p[1]);
        return ans;
    }
}
