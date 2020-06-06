class Solution {
    public List<String> generateParenthesis(int n) {
        StringBuilder sb = new StringBuilder();
        List<String> ans = new ArrayList<>();
        dfs(n, n, sb, ans);
        return ans;
    }
    public void dfs(int left, int right, StringBuilder sb, List<String> ans) {
        if(left > right) return;
        if(left == 0 && right == 0) {
            ans.add(sb.toString());
        }
        if(left > 0) {
            sb.append("(");
            dfs(left - 1, right, sb, ans);
            sb.setLength(sb.length() - 1);
        }
        if(right > 0) {
            sb.append(")");
            dfs(left, right - 1, sb, ans);
            sb.setLength(sb.length() - 1);
        }
    }
}
