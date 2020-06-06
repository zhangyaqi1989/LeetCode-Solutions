class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        Map<String, Integer> counter = new HashMap<>();
        for(int [] d : dominoes) {
            int a = Math.min(d[0], d[1]);
            int b = Math.max(d[0], d[1]);
            String key = a + " " + b;
            counter.put(key, counter.getOrDefault(key, 0) + 1);
        }
        int ans = 0;
        for(String key : counter.keySet()) {
            int cnt = counter.get(key);
            ans += cnt * (cnt - 1);
        }
        return ans / 2;
    }
}
