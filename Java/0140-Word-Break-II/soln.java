class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        Set<String> words = new HashSet<>();
        for(String word : wordDict) words.add(word);
        HashMap<String, ArrayList<String>> memo = new HashMap<String, ArrayList<String>>();
        return dfs(s, words, memo);
    }
    
    public List<String> dfs(String s, Set<String> words, HashMap<String, ArrayList<String>> memo) {
        if (memo.containsKey(s)) return memo.get(s);
        ArrayList<String> ans = new ArrayList<>();
        if (s.length() == 0) {
            ans.add("");
            return ans;
        }
        for(String word : words) {
            if (s.startsWith(word)) {
                List<String> rests = dfs(s.substring(word.length()), words, memo);
                for(String rest : rests) {
                    ans.add(word + (rest.length() == 0 ? "" : " ") + rest);
                }
            }
        }
        memo.put(s, ans);
        return ans;
    }
}
