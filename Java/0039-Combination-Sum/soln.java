class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        dfs(target, 0, candidates, path, ans);
        return ans;
    }
    
    public void dfs(int target, int idx, int[] candidates, List<Integer> path, List<List<Integer>> ans) {
        if (target == 0) {
            List<Integer> temp = new ArrayList<>(path);
            ans.add(temp);
        } else if (target > 0) {
            for(int i = idx; i < candidates.length; ++i) {
                path.add(candidates[i]);
                dfs(target - candidates[i], i, candidates, path, ans);
                path.remove(path.size() - 1);
            }
        }
    }
}
