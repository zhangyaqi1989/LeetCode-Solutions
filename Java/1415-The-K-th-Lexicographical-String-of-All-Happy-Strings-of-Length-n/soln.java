class Solution {
    public String getHappyString(int n, int k) {
        List<String> ans = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        dfs(sb, n, ans);
        if(ans.size() < k) return "";
        Collections.sort(ans);
        return ans.get(k - 1);
    }
    
    private void dfs(StringBuilder sb, int n, List<String> ans) {
        if(sb.length() == n) ans.add(sb.toString());
        else {
            char[] nxts = {'a', 'b', 'c'};
            for(char nxt : nxts) {
                if (sb.length() > 0 && sb.charAt(sb.length() - 1) == nxt) continue;
                sb.append(nxt);
                dfs(sb, n, ans);
                sb.setLength(sb.length() - 1);
            }
        }
    }
}
