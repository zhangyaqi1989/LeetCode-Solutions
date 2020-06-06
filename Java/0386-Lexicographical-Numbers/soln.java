class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> ans = new ArrayList<>();
        helper(1, n, ans);
        return ans;
    }
    
    private void helper(int cur, int n, List<Integer> ans) {
        if (cur > n) return;
        ans.add(cur);
        helper(cur * 10, n, ans);
        if(cur % 10 != 9) helper(cur + 1, n, ans);
    }
}
