class Solution {
    public int flipgame(int[] fronts, int[] backs) {
        Set<Integer> same = new HashSet<>();
        int n = fronts.length;
        for(int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) same.add(fronts[i]);
        }
        int ans = Integer.MAX_VALUE;
        for(int front : fronts) {
            if (!same.contains(front)) ans = Math.min(ans, front);
        }
        for(int back : backs) {
            if (!same.contains(back)) ans = Math.min(ans, back);
        }
        return ans == Integer.MAX_VALUE ? 0 : ans;
    }
}
