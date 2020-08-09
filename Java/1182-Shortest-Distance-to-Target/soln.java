class Solution {
    public List<Integer> shortestDistanceColor(int[] colors, int[][] queries) {
        List<Integer> [] idxes = new ArrayList[4];
        for(int i = 0; i < 4; ++i) idxes[i] = new ArrayList<>();
        final int N = colors.length;
        for(int i = 0; i < N; ++i) {
            idxes[colors[i]].add(i);
        }
        List<Integer> ans = new ArrayList<>();
        for(int [] query : queries) {
            int idx = query[0], c = query[1];
            List<Integer> lst = idxes[c];
            if(lst.isEmpty()) {
                ans.add(-1);
                continue;
            }
            int n = lst.size();
            int lo = 0, hi = n;
            // find the first i such that lst[i] >= idx
            while(lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if(lst.get(mid) >= idx) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            int best = 2 * N;
            if(lo > 0) best = idx - lst.get(lo - 1);
            if(lo < n) best = Math.min(best, lst.get(lo) - idx); 
            ans.add(best);
        }
        return ans;
    }
}
