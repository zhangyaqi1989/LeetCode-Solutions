class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> ans = new ArrayList<String>();
        for(String word : words)
        {
            if(isMatch(word, pattern)) ans.add(word);
        }
        return ans;
        
    }
    
    boolean isMatch(String word1, String word2) {
        if(word1.length() != word2.length()) return false;
        Map<Character, Character> m1 = new HashMap<Character, Character>();
        Map<Character, Character> m2 = new HashMap<Character, Character>();
        for(int i = 0; i < word1.length(); ++i)
        {
            char ch1 = word1.charAt(i);
            char ch2 = word2.charAt(i);
            if (m1.containsKey(ch1) && m1.get(ch1) != ch2) return false;
            m1.put(ch1, ch2);
            if (m2.containsKey(ch2) && m2.get(ch2) != ch1) return false;
            m2.put(ch2, ch1);
        }
        return true;
    }
}