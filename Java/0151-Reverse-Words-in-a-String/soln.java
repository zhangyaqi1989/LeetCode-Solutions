class Solution {
    public String reverseWords(String s) {
        String [] tokens = s.trim().split("\\s+");
        List<String> ans = new ArrayList<>();
        int n = tokens.length;
        for(int i = n - 1; i >= 0; --i) ans.add(tokens[i]);
        return String.join(" ", ans);
    }
}
