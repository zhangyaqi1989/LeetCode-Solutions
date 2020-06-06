class Solution {
    public int[] shortestToChar(String S, char C) {
        List<Integer> idxes = new ArrayList<>();
        idxes.add(-20000);
        int n = S.length();
        for(int i = 0; i < n; ++i) {
            if (S.charAt(i) == C) idxes.add(i); 
        }
        idxes.add(20000);
        int[] ans = new int[n];
        int left = 0;
        for(int i = 0; i < n; ++i) {
            if (i >= idxes.get(left + 1)) ++left;
            // System.out.println(left);
            ans[i] = Math.min(i - idxes.get(left), idxes.get(left + 1) - i);
        }
        return ans;
    }
}
