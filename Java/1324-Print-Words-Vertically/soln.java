class Solution {
    public List<String> printVertically(String s) {
        String [] tokens = s.split(" ");
        int mx = -1;
        for(String token : tokens) mx = Math.max(mx, token.length());
        StringBuilder [] sbs = new StringBuilder[mx];
        int n = tokens.length;
        for(int i = 0; i < mx; ++i) {
            sbs[i] = new StringBuilder();
            for(int j = 0; j < n; ++j) {
                if (i < tokens[j].length()) sbs[i].append(tokens[j].charAt(i));
                else sbs[i].append(' ');
            }
        }
        List<String> ans = new ArrayList<>();
        for(int i = 0; i < mx; ++i) {
            String token = sbs[i].toString();
            ans.add(token.replaceAll("\\s+$", ""));
        }
        return ans;
    }
}
