class Solution {
    public boolean pyramidTransition(String bottom, List<String> allowed) {
        Map<String, List<String>> allows = new HashMap<>();
        for(String str : allowed) {
            String ab = str.substring(0, 2);
            allows.putIfAbsent(ab, new ArrayList<>());
            allows.get(ab).add(str.substring(2, 3));
        }
        return isValid(bottom, allows);
    }
    
    private boolean isValid(String row, Map<String, List<String>> allows) {
        if(row.length() == 1) return true;
        List<String> cands = nextRows(row, allows);
        for(String cand : cands) {
            if(isValid(cand, allows)) return true;
        }
        return false;
    }
    
    private List<String> nextRows(String row, Map<String, List<String>> allows) {
        List<String> ans = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        dfs(0, sb, row, allows, ans);
        return ans;
    }
    
    private void dfs(int idx, StringBuilder sb, String row, Map<String, List<String>> allows, List<String> ans) {
        if (idx == row.length() - 1) {
            ans.add(sb.toString());
            return;
        }
        String key = row.substring(idx, idx + 2);
        if (allows.containsKey(key)) {
            for(String nxt : allows.get(key)) {
                sb.append(nxt);
                dfs(idx + 1, sb, row, allows, ans);
                sb.setLength(sb.length() - 1);
            }
        }
    }
}
