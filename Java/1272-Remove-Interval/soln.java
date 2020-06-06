class Solution {
    public List<List<Integer>> removeInterval(int[][] intervals, int[] toBeRemoved) {
        List<List<Integer>> ans = new ArrayList<>();
        int rs = toBeRemoved[0], re = toBeRemoved[1];
        for(int [] interval : intervals) {
            int s = interval[0], e = interval[1];
            if (rs >= e || s >= re) {
                ans.add(Arrays.asList(s, e));
            } else {
                if (s < rs) {
                    ans.add(Arrays.asList(s, rs));
                }
                if (e > re) {
                    ans.add(Arrays.asList(re, e));
                }
            }
        }
        return ans;
    }
}
