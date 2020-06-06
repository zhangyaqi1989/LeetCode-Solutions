class MagicDictionary {
    
    public Set<String> words;
    public Map<String, Integer> m;

    /** Initialize your data structure here. */
    public MagicDictionary() {
        words = new HashSet<>();
        m = new HashMap<>();
    }
    
    /** Build a dictionary through a list of words */
    public void buildDict(String[] dict) {
        for(String word : dict) {
            words.add(word);
            int n = word.length();
            for(int i = 0; i < n; ++i) {
                String temp = word.substring(0, i) + "#" + word.substring(i + 1);
                m.put(temp, m.getOrDefault(temp, 0) + 1);
            }
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    public boolean search(String word) {
        int val = words.contains(word) ? 1 : 0;
        int n = word.length();
        for(int i = 0; i < n; ++i) {
            String temp = word.substring(0, i) + "#" + word.substring(i + 1);
            // if (m.get(temp) != null && m.get(temp) > val) return true;
            if (m.getOrDefault(temp, 0) > val) return true;
        }
        return false;
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * boolean param_2 = obj.search(word);
 */
