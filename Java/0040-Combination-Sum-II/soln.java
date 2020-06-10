class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> combo = new ArrayList<>();
        dfs(target, 0, candidates, combo, ans);
        return ans;
    }
    
    public void dfs(int target, int idx, int [] candidates, List<Integer> combo, List<List<Integer>> ans) {
        if (target == 0) {
            List<Integer> temp = new ArrayList<>(combo);
            ans.add(temp);
        } else if (target > 0) {
            for(int i = idx; i < candidates.length; ++i) {
                if (i > idx && candidates[i] == candidates[i - 1]) continue;
                combo.add(candidates[i]);
                dfs(target - candidates[i], i + 1, candidates, combo, ans);
                combo.remove(combo.size() - 1);
            }
        }
    }
}
