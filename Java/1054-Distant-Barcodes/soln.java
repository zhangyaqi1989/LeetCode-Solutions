class Solution {
    public int[] rearrangeBarcodes(int[] packages) {
        int n = packages.length;
        int [] ans = new int [n];
        Map<Integer, Integer> counter = new HashMap<>();
        for(int p : packages) counter.put(p, counter.getOrDefault(p, 0) + 1);
        int [][] pairs = new int [n][2];
        int idx = 0;
        for(int x : counter.keySet()) {
            pairs[idx][0] = -counter.get(x);
            pairs[idx][1] = x;
            ++idx;
        }
        Arrays.sort(pairs, (a, b)->(a[0] - b[0]));
        List<Integer> nums = new ArrayList<>();
        for(int [] pair : pairs) {
            int cnt = -pair[0];
            for(int i = 0; i < cnt; ++i) nums.add(pair[1]);
        }
        idx = 0;
        for(int i = 0; i < n; i += 2) ans[i] = nums.get(idx++);
        for(int i = 1; i < n; i += 2) ans[i] = nums.get(idx++);
        return ans;
    }
}
