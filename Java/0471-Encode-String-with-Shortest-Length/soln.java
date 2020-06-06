class Solution {
    public String encode(String s) {
        memo = new HashMap<>();
        return helper(s);
    }
    
    public String helper(String s) {
        if (s.length() == 0) return "";
        if (memo.containsKey(s)) return memo.get(s);
        String ans = s;
        int n = s.length();
        int idx = (s + s).indexOf(s, 1);
        if (idx < n) {
            String one = idx < n ? Integer.toString(n / idx) + "[" + helper(s.substring(0, idx)) + "]" : s;
            if (one.length() < n) ans = one;
        }
        for(int i = 1; i < n; ++i) {
            String temp = helper(s.substring(0, i)) + helper(s.substring(i));
            if (temp.length() < ans.length()) ans = temp;
        }
        memo.put(s, ans);
        return ans;
    }
    
    private Map<String, String> memo;
}
