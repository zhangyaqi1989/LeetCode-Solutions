class Solution {
    public int totalFruit(int[] tree) {
        Map<Integer, Integer> counter = new HashMap<>();
        int lo = 0, ans = 0, n = tree.length;
        for(int i = 0; i < n; ++i) {
            counter.put(tree[i], counter.getOrDefault(tree[i], 0) + 1);
            while (counter.size() > 2) {
                int cnt = counter.get(tree[lo]);
                if (cnt == 1) {
                    counter.remove(tree[lo]);
                } else {
                    counter.put(tree[lo], cnt - 1);
                }
                ++lo;
            }
            ans = Math.max(ans, i - lo + 1);
        }
        return ans;
    }
}
