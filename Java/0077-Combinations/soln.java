class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> combo = new ArrayList<>();
        helper(n, k, combo, ans);
        return ans;
    }
    
    public void helper(int n, int k, List<Integer> combo, List<List<Integer>> ans) {
        if (combo.size() == k) ans.add(new ArrayList<>(combo));
        else {
            int start = combo.isEmpty() ? 1 : combo.get(combo.size() - 1) + 1;
            for(int i = start; i <= n; ++i) {
                combo.add(i);
                helper(n, k, combo, ans);
                combo.remove(combo.size() - 1);
            }
        }
    } 
}
