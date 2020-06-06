class Solution {
    public int largestValsFromLabels(int[] values, int[] labels, int num_wanted, int use_limit) {
        List<int []> pairs = new ArrayList<>();
        int n = values.length;
        for(int i = 0; i < n; ++i) {
            pairs.add(new int [] {values[i], labels[i]});
        }
        Collections.sort(pairs, (a, b) -> (b[0] - a[0]));
        int ans = 0;
        Map<Integer, Integer> used = new HashMap<>();
        for(int [] p : pairs) {
            if (used.getOrDefault(p[1], 0) < use_limit) {
                used.put(p[1], used.getOrDefault(p[1], 0) + 1);
                ans += p[0];
                if (--num_wanted == 0) break;
            }
        }
        return ans;
        
    }
}
