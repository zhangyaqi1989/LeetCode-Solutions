class Solution {
    public int[] shortestToChar(String S, char C) {
        List<Integer> idxes = new ArrayList<>();
        int n = S.length();
        idxes.add(-20000);
        for(int i = 0; i < n; ++i) {
            if (S.charAt(i) == C) idxes.add(i);
        }
        idxes.add(40000);
        int idx = 0;
        int [] ans = new int [n];
        for(int i = 0; i < n; ++i) {
            while (idxes.get(idx) < i) ++idx;
            ans[i] = Math.min(idxes.get(idx) - i, i - idxes.get(idx - 1));
        }
        return ans;
    }
}
