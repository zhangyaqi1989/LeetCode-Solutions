class Solution {
    public List<String> addOperators(String num, int target) {
        List<String> ans = new ArrayList<>();
        for(int i = 1; i <= num.length(); ++i) {
            if (i > 1 && num.charAt(0) == '0') continue;
            String nxt = num.substring(0, i);
            long val = Long.parseLong(nxt);
            dfs(num, i, nxt, val, val, target, ans);
        }
        return ans;
    }
    
    public void dfs(String num, int idx, String expr, long cur, long last, int target, List<String> ans) {
        if (idx == num.length()) {
            if (cur == target) {
                ans.add(expr);
            }
        } else {
            for(int i = idx + 1; i <= num.length(); ++i) {
                if (i - idx > 1 && num.charAt(idx) == '0') continue;
                String nxt = num.substring(idx, i);
                long val = Long.parseLong(nxt);
                dfs(num, i, expr + "+" + nxt, cur + val, val, target, ans);
                dfs(num, i, expr + "-" + nxt, cur - val, -val, target, ans);
                dfs(num, i, expr + "*" + nxt, cur - last + last * val, last * val, target, ans);
            }
        }
    }
}
