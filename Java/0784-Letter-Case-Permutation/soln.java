class Solution {
    public List<String> letterCasePermutation(String S) {
        List<String> ans = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        dfs(S, 0, sb, ans);
        return ans;
    }
    
    private void dfs(String S, int idx, StringBuilder sb, List<String> ans) {
        if (idx == S.length()) {
            ans.add(sb.toString());
        } else {
            char ch = S.charAt(idx);
            if (Character.isLetter(ch)) {
                sb.append(Character.toLowerCase(ch));
                dfs(S, idx + 1, sb, ans);
                sb.setLength(sb.length() - 1);
                sb.append(Character.toUpperCase(ch));
                dfs(S, idx + 1, sb, ans);
                sb.setLength(sb.length() - 1);
            } else {
                sb.append(ch);
                dfs(S, idx + 1, sb, ans);
                sb.setLength(sb.length() - 1);
            }
        }
    }
}
