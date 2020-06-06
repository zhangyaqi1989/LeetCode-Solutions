class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> combo = new ArrayList<>();
        dfs(k, 1, n, combo, ans);
        return ans;
    }
    
    public void dfs(int k, int num, int target, List<Integer> combo, List<List<Integer>> ans) {
        if (target < 0 || combo.size() > k) return;
        if (target == 0) {
            if (combo.size() == k) {
                List<Integer> temp = new ArrayList<>(combo);
                ans.add(temp);
            }
        } else {
            for(int nxt = num; nxt < 10; ++nxt) {
                combo.add(nxt);
                dfs(k, nxt + 1, target - nxt, combo, ans);
                combo.remove(combo.size() - 1);
            }
        }
    }
}
